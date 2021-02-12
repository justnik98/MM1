//
// Created by justnik on 05.02.2021.
//

#include <cmath>
#include "MM1.h"

using namespace std;

void MM1::modeling(double in, double u, size_t num) {
    Random r(2 + u / in);
    size_t qLen = 0;
    size_t sum = 0;
    meanQLen = 0;
    size_t t = 0;
    while (t <= num) {
        sum += qLen;
        qLen += r.randPoisson(in);
        qLen -= min(qLen, static_cast<size_t> (r.randPoisson(u)));
        ++t;
    }
    meanQLen = static_cast<double> (sum) / num;
}
