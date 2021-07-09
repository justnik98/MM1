//
// Created by justnik on 10.05.2021.
//
#define N

#include "theory.h"

#ifdef N

double qLen(double in, double u, double cov) {
    double p = in / u;
    double r1 = p * p / (1 - p);
    double r2 = -cov * p / (1 - p);
    double res = r1 + p + r2 + (1 - p);
    return res;
}

#elif defined(N2)

double qLen(double in, double u, double cov) {
    double p = in / u;
    double m_in = 1.0 / in;
    double m_u = 1.0 / u;
    double d1 = m_in * m_in;
    double d2 = m_u * m_u;
    double r1 = (d1 + d2 - 2 * cov) / (2 * (m_in - m_u));
    double r2 = (m_in - m_u) / 2;
    double res = (r1 + r2) * p;
    return res;
}
#endif