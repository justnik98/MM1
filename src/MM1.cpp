//
// Created by justnik on 05.02.2021.
//

#include <cmath>
#include "MM1.h"

using namespace std;

void MM1::modeling(double in, double u, size_t num, uint8_t rule) {
    size_t qLen = 0;
    size_t sum = 0;
    meanQLen = 0;
    size_t t = 0;
    while (t <= num) {
        sum += qLen;
        auto[in_, out_] = gen(in, u, rule);
        qLen += in_;
        qLen -= min(qLen, out_);
        ++t;
    }
    meanQLen = static_cast<double> (sum) / num;
}

MM1::MM1() {
    P.resize(10);
    for (auto i = 0; i < trunc_size; ++i) {
        P[0].push_back((pow(e, -0.1) * pow(0.1, i) / factorial(i)) + (P[0].empty() ? 0 : P[0].back()));
        P[1].push_back((pow(e, -0.2) * pow(0.2, i) / factorial(i)) + (P[1].empty() ? 0 : P[1].back()));
        P[2].push_back((pow(e, -0.3) * pow(0.3, i) / factorial(i)) + (P[2].empty() ? 0 : P[2].back()));
        P[3].push_back((pow(e, -0.4) * pow(0.4, i) / factorial(i)) + (P[3].empty() ? 0 : P[3].back()));
        P[4].push_back((pow(e, -0.5) * pow(0.5, i) / factorial(i)) + (P[4].empty() ? 0 : P[4].back()));
        P[5].push_back((pow(e, -0.6) * pow(0.6, i) / factorial(i)) + (P[5].empty() ? 0 : P[5].back()));
        P[6].push_back((pow(e, -0.7) * pow(0.7, i) / factorial(i)) + (P[6].empty() ? 0 : P[6].back()));
        P[7].push_back((pow(e, -0.8) * pow(0.8, i) / factorial(i)) + (P[7].empty() ? 0 : P[7].back()));
        P[8].push_back((pow(e, -0.9) * pow(0.9, i) / factorial(i)) + (P[8].empty() ? 0 : P[8].back()));
        P[9].push_back((pow(e, -1) * pow(1, i) / factorial(i)) + (P[9].empty() ? 0 : P[9].back()));
    }
}

double MM1::factorial(size_t n) {
    double res = 1;
    for (auto i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

size_t MM1::getvalue(double x, double in) {
    size_t res = 0;
    size_t ind = round(in * 10) - 1;
    while (res < trunc_size && x > P[ind][res]) {
        ++res;
    }
    return res;
}

std::pair<size_t, size_t> MM1::gen(double in, double u, uint8_t rule) {
    Random r;
    size_t t1 = 0;
    size_t t2 = 0;
    double x;
    switch (rule) {
        case 0:
            t1 = getvalue(r.rnd(), in);
            t2 = getvalue(r.rnd(), u);
            break;

        case 1:
            x = r.rnd();
            t1 = getvalue(x, in);
            t2 = getvalue(1 - x, u);
            break;

        case 2:
            x = r.rnd();
            t1 = getvalue(x, in);
            t2 = getvalue(x, u);
            break;

        default:
            exit(-1);
    }
    return make_pair(t1, t2);
}
