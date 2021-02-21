//
// Created by justnik on 05.02.2021.
//

#include "MM1.h"

using namespace std;

void MM1::theory(double in, double u) {
    auto r = in / u;
    delay = u * r / (1 - r);
}

void MM1::theoryN(double in, double u) {
    double r = in / u;
    meanQlen = r / (1 - r);
}

void MM1::modeling(double in, double u, size_t num, uint8_t rule) {
    list<msg> q;
    vector<msg> m;
    size_t outCount = 0;
    delay = 0;
    meanQlen = 0;
    emptyP1 = 0;
    emptyP2 = 0;
    tau1 = 0;
    tau2 = 0;
    n_in = 0;
    n_out = 0;
    meanTU = 0;
    size_t sum = 0;
    double t = 0;
    double tU = 0;
    while (t < num) {
        auto[t1, t2] = gen(in, u, rule);
        t += t1;
        tU = t2;
        meanTU += tU;
        m.emplace_back(t, tU);
    }
    t = 0;
    auto it = m.begin();
    while (t < num) {
        for (; it != m.end(); ++it) {
            if ((*it).arr < t) {
                if (q.empty()) {
                    emptyP1 += 1;
                } else {
                    it->tau = (q.front().in == 0 ? t : q.front().in) + q.front().tU - t;
                    tau1 += it->tau;
                }
                n_in += q.size();
                q.push_back(*it);
            } else break;
        }
        if (q.empty()) {
            emptyP2 += step;
        }
        sum += q.size();
        if (!q.empty()) {
            //t += q.front().tU;
            if (q.front().in == 0) {
                q.front().in = t;
            }
            if (t >= (q.front().in + q.front().tU)) {
                delay += t - q.front().arr;
                T1 += t - q.front().arr - q.front().tau - q.front().tU;
                outCount++;
                q.pop_front();
                n_out += q.size();
            }
        }
        t += step;
    }
    delay = delay / outCount;
    meanQlen = static_cast<double>(sum) * step / num;
    tau2 = tau1 / (m.size() - emptyP1);
    T2 = T1 / (m.size() - emptyP1);
    T1 /= m.size();
    emptyP1 /= m.size();
    emptyP2 /= num;
    tau1 /= m.size();
    n_in /= m.size();
    n_out /= m.size();
    meanTU /= m.size();
}

std::pair<double, double> MM1::gen(double in, double u, uint8_t rule) {
    Random r;
    double t1 = 0;
    double t2 = 0;
    double tmp;
    switch (rule) {
        case 0:
            t1 = r.randExp(in);
            t2 = r.randExp(u);
            break;

        case 1:
            do {
                tmp = r.rnd();
            } while (tmp == 0 || tmp == 1);
            t1 = (-log(tmp) / in);
            t2 = (-log(tmp) / u);
            break;

        case 2:
            do {
                tmp = r.rnd();
            } while (tmp == 0);
            t1 = (-log(tmp) / in);
            t2 = (-log(1 - tmp) / u);
            break;

        default:
            exit(-1);
    }
    return make_pair(t1, t2);
}