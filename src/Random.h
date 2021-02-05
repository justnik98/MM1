//
// Created by justnik on 05.02.2021.
//

#ifndef MM1_RANDOM_H
#define MM1_RANDOM_H


#include <iostream>
#include <cstdlib>
#include <cmath>

class Random {
private:
    uint32_t i = 0;
    const uint32_t mask1 = 1 << 31;
    const uint32_t mask2 = mask1 - 1;
    const uint32_t p = 624;
    const uint32_t w = 32;
    const uint32_t r = 31;
    const uint32_t q = 397;
    const uint32_t a = 0x9908b0df;
    const uint32_t u = 11;
    const uint32_t s = 7;
    const uint32_t t = 15;
    const uint32_t l = 18;
    const uint32_t b = 0x9d2c5680;
    const uint32_t c = 0xefc60000;
    uint32_t *X;
public:
    Random();

    Random(uint32_t seed);

    ~Random();

    uint32_t rand();

    double rnd();

    double randGaussian(double mean = 0, double sigma = 1);

    double randExp(double lyambda);

    double randRayleigh(double sigma = 1);

    double randCauchy(double x0, double gamma);

    double randChi2(size_t k);

    double randLogistic(double mean, double sigma);

    double randStudentT(size_t k);
};


#endif //MM1_RANDOM_H
