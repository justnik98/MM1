//
// Created by justnik on 05.02.2021.
//

#include "Random.h"

using namespace std;

Random::Random() {
    X = new uint32_t[624];
    for (size_t i = 0; i < 624; ++i) {
        X[i] = std::rand();
    }
}

Random::Random(uint32_t seed) {
    srand(seed);
    X = new uint32_t[624];
    for (size_t i = 0; i < 624; ++i) {
        X[i] = std::rand();
    }
}

Random::~Random() {
    delete[] X;
}

uint32_t Random::rand() {
    uint32_t y = (X[i] & mask1) + (X[i + 1] & mask2);
    if (y & 1) {
        X[i] = X[(i + q) % p] ^ (y >> 1) ^ a;
    } else {
        X[i] = X[(i + q) % p] ^ (y >> 1);
    }
    y = X[i] ^ (y >> u) ^ ((y << s) & b) ^ ((y << t) & c) ^ (y >> l);
    i++;
    i %= p;
    return y;
}

double Random::rnd() {
    return static_cast<double>(Random::rand()) / UINT32_MAX;
}

double Random::randGaussian(double mean, double sigma) {
    static uint8_t ind = 0;
    static double z[2];
    if (ind) {
        ind ^= 1;
        return z[1] * sigma + mean;
    }
    double s = 0;
    double x = 0;
    double y = 0;
    while (s == 0 || s > 1) {
        x = rnd() * (-2) + 1;
        y = rnd() * (-2) + 1;
        s = x * x + y * y;
    }
    double val = sqrt((-2.0 * log(s) / s));
    z[0] = x * val;
    z[1] = y * val;
    ind ^= 1;
    return z[0] * sigma + mean;
}

double Random::randExp(double mean) {
    double d;
    do {
        d = rnd();
    } while (!d);
    return -log(rnd()) / mean;
}

double Random::randRayleigh(double sigma) {
    return sqrt(pow(randGaussian(0, sigma), 2) + pow(randGaussian(0, sigma), 2));
}

double Random::randCauchy(double x0, double gamma) {
    double x, y;
    do {
        x = rnd() * (-2) + 1;
        y = rnd() * (-2) + 1;
    } while ((x * x + y * y) > 1.0 || !y);
    return x0 + gamma * x / y;
}

double Random::randChi2(size_t k) {
    double res = 0;
    double r;
    for (size_t i = 0; i < k; ++i) {
        r = randGaussian();
        res += r * r;
    }
    return sqrt(res);
}

double Random::randLogistic(double mean, double sigma) {
    double r = rnd();
    while (r == 1 || r == 0) {
        r = rnd();
    }
    return mean + sigma * log(1.0 / r - 1);
}

double Random::randStudentT(size_t k) {
    if (k == 1) {
        return randCauchy(0, 1);
    }
    return randGaussian() / sqrt(randChi2(k) / k);
}
