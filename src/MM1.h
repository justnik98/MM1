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
    double meanQLen = 0;
public:
    MM1() = default;

    void modeling(double in, double u, size_t num);

    [[nodiscard]] double getMeanQLen() const { return meanQLen; }

};


#endif //MM1_MM1_H
