//
// Created by justnik on 05.02.2021.
//

#ifndef MM1_MM1_H
#define MM1_MM1_H


#include <list>
#include <map>
#include <vector>
#include <queue>
#include "Random.h"

class MM1 {
private:
    const uint16_t trunc_size = 100;
    const double e = 2.718281828;
    std::vector<std::vector<double>> P;

    double meanQLen = 0;

    [[nodiscard]] static double factorial(size_t n);

    size_t getvalue(double x, double in);

    std::pair<size_t, size_t> gen(double in, double u, uint8_t rule);

public:
    MM1();

    void modeling(double in, double u, size_t num, uint8_t rule);

    [[nodiscard]] double getMeanQLen() const { return meanQLen; }

};


#endif //MM1_MM1_H
