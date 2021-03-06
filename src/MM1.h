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
        double tau = 0;
        msg(double in, double t) : arr(in), tU(t) {};
    };

    double delay = 0;

    double meanQlen = 0;

    double emptyP1 = 0;

    double emptyP2 = 0;

    double tau1 = 0;

    double tau2 = 0;

    double n_in = 0;

    double n_out = 0;

    double meanTU = 0;

    double step = 0.001;

    double T1 = 0;

    double T2 = 0;

    static std::pair<double, double> gen(double in, double u, uint8_t rule);

public:
    MM1() = default;

    void theory(double in, double u);

    void modeling(double in, double u, size_t num, uint8_t rule);

    [[nodiscard]] double getDelay() const { return delay; }

    [[nodiscard]] double getMeanQlen() const { return meanQlen; }

    [[nodiscard]] double getEmptyP1() const { return emptyP1; }

    [[nodiscard]] double getEmptyP2() const { return emptyP2; }

    [[nodiscard]] double getTau1() const { return tau1; }

    [[nodiscard]] double getTau2() const { return tau2; }

    [[nodiscard]] double getNIn() const { return n_in; }

    [[nodiscard]] double getNOut() const { return n_out; }

    [[nodiscard]] double getMeanTU() const { return meanTU; }

    [[nodiscard]] double getT1() const { return T1; }

    [[nodiscard]] double getT2() const { return T2; }

    void theoryN(double in, double u);
};


#endif //MM1_MM1_H
