//
// Created by justnik on 05.02.2021.
//

#ifndef MM1_MM1_H
#define MM1_MM1_H


#include <list>
#include <vector>
#include <queue>
#include "Random.h"

class MM1 {
private:
    class msg {
    public:
        double arr = 0;
        double tU = 0;
        double in = 0;

        msg(double in, double t) : arr(in), tU(t) {};
    };

    double delay = 0;

    double meanQlen = 0;

    double emptyP1 = 0;

    double emptyP2 = 0;

    double tau1 = 0;

    double tau2 = 0;

    double step = 0.001;
public:
    MM1() = default;

    void theory(double in, double u);

    void modelingv0(double in, double u, size_t num);

    void modelingv1(double in, double u, size_t num);

    void modelingv2(double in, double u, size_t num);

    [[nodiscard]] double getDelay() const { return delay; }

    [[nodiscard]] double getMeanQlen() const { return meanQlen; }

    [[nodiscard]] double getEmptyP1() const { return emptyP1; }

    [[nodiscard]] double getEmptyP2() const { return emptyP2; }

    [[nodiscard]] double getTau1() const { return tau1; }

    [[nodiscard]] double getTau2() const { return tau2; }

    void theoryN(double in, double u);
};


#endif //MM1_MM1_H
