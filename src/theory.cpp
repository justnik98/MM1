//
// Created by justnik on 10.05.2021.
//

#include "theory.h"

double qLen(double in, double u, double cov) {
    double p = in / u;
    double r1 = p * p / (1 - p);
    double r2 = -cov * p / (1 - p);
    double res = r1 + p + r2 + (1 - p);
    return res;
}
