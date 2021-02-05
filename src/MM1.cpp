//
// Created by justnik on 05.02.2021.
//

#include "MM1.h"

using namespace std;

void MM1::theory(double in, double u) {
    delay = 1 / (u * (1 - in / u));
}

void MM1::theoryN(double in, double u) {
    double r = in / u;
    meanQlen = r / (1 - r);
}

void MM1::modelingv0(double in, double u, size_t num) {

    Random r;
    list<msg> q;
    vector<msg> m;
    size_t outCount = 0;
    delay = 0;
    meanQlen = 0;
    emptyP1 = 0;
    emptyP2 = 0;
    size_t nempty = 0;
    double step = 0.1;
    double t = 0;
    double tU = 0;
    while (t < num) {
        t += r.randExp(in);
        tU = r.randExp(u);
        m.emplace_back(t, tU);
    }
    t = 0;
    auto it = m.begin();
    while (t < num) {
        for (; it != m.end(); ++it) {
            if ((*it).arr < t) {
                if (q.empty()) {
                    emptyP1 += 1;
                }
                q.push_back(*it);
            } else break;
        }
        if (q.empty()) {
            emptyP2 += step;
        }
        meanQlen += q.size() * step;
        if (!q.empty()) {
            t += q.front().tU;
            delay += t - q.front().arr;
            outCount++;
            q.pop_front();
        } else {
            t += step;
        }
    }
    delay = delay / outCount;
    meanQlen /= num;
    emptyP1 /= m.size();
    emptyP2 /= num;
}

void MM1::modelingv1(double in, double u, size_t num) {
    Random r;
    list<msg> q;
    vector<msg> m;
    size_t outCount = 0;
    delay = 0;
    meanQlen = 0;
    double step = 0.1;
    double t = 0;
    double tmp = 0;
    double tU = 0;
    while (t < num) {
        do {
            tmp = r.rnd();
        } while (tmp == 0);
        t += (-log(tmp) / in);
        tU = (-log(1 - tmp) / u);
        m.emplace_back(t, tU);
    }
    t = 0;
    auto it = m.begin();
    uint16_t percents = 0;

    while (t < num) {
        /*if ((t * 100.0 / num) >= (percents + 1)) {
            percents++;
            cout << "\r" << percents << "%";
        }*/
        for (it; it != m.end(); ++it) {
            if ((*it).arr < t) {
                if (q.empty()) {
                    emptyP1 += 1;
                }
                q.push_back(*it);
            } else break;
        }
        if (q.empty()) {
            emptyP2 += step;
        }
        meanQlen += q.size() * step;
        if (!q.empty()) {
            t += q.front().tU;
            delay += t - q.front().arr;
            outCount++;
            q.pop_front();
        } else {
            t += step;
        }
    }
    delay /= outCount;
    meanQlen /= num;
    emptyP1 /= outCount;
    emptyP2 /= num;
}

void MM1::modelingv2(double in, double u, size_t num) {
    Random r;
    list<msg> q;
    vector<msg> m;
    size_t outCount = 0;
    delay = 0;
    meanQlen = 0;
    double step = 0.1;
    double t = 0;
    double tmp = 0;
    double time = 0;
    double tU = 0;
    while (t < num) {
        do {
            tmp = r.rnd();
        } while (tmp == 0);
        time = (-log(tmp) / in);
        t += time;
        tU = (-log(tmp) / u);
        m.emplace_back(t, tU);
    }
    t = 0;
    auto it = m.begin();
    uint16_t percents = 0;

    while (t < num) {
        /*if ((t * 100.0 / num) >= (percents + 1)) {
            percents++;
            cout << "\r" << percents << "%";
        }*/
        for (it; it != m.end(); ++it) {
            if ((*it).arr < t) {
                if (q.empty()) {
                    emptyP1 += 1;
                }
                q.push_back(*it);
            } else break;
        }
        if (q.empty()) {
            emptyP2 += step;
        }
        meanQlen += q.size() * 0.1;
        if (!q.empty()) {
            t += q.front().tU;
            delay += t - q.front().arr;
            outCount++;
            q.pop_front();
        } else {
            t += step;
        }
    }
    delay /= outCount;
    meanQlen /= num;
    emptyP1 /= m.size();
    emptyP2 /= num;
}
