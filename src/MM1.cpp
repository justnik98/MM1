//
// Created by justnik on 05.02.2021.
//

#include "MM1.h"

using namespace std;

void MM1::theory(double in, double u) {
    auto r = in / u;
    delay = u * r / (1 - r);
    //delay = 1 / (u * (1 - in / u));

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
    tau1 = 0;
    tau2 = 0;
    size_t sum = 0;
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
                } else {
                    tau1 += (q.front().in == 0 ? t : q.front().in) + q.front().tU - t;
                }
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
                outCount++;
                q.pop_front();
            }
        }
        t += step;
    }
    delay = delay / outCount;
    meanQlen = static_cast<double>(sum) * step / num;
    tau2 = tau1 / (m.size() - emptyP1);
    emptyP1 /= m.size();
    emptyP2 /= num;
    tau1 /= m.size();
}

void MM1::modelingv1(double in, double u, size_t num) {
    Random r;
    list<msg> q;
    vector<msg> m;
    size_t outCount = 0;
    delay = 0;
    meanQlen = 0;
    emptyP1 = 0;
    emptyP2 = 0;
    tau1 = 0;
    tau2 = 0;
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

    while (t < num) {
        /*if ((t * 100.0 / num) >= (percents + 1)) {
            percents++;
            cout << "\r" << percents << "%";
        }*/
        for (; it != m.end(); ++it) {
            if ((*it).arr < t) {
                if (q.empty()) {
                    emptyP1 += 1;
                } else {
                    tau1 += (q.front().in == 0 ? t : q.front().in) + q.front().tU - t;
                }
                q.push_back(*it);
            } else break;
        }
        if (q.empty()) {
            emptyP2 += step;
        }
        meanQlen += q.size();
        if (!q.empty()) {
            //t += q.front().tU;
            if (q.front().in == 0) {
                q.front().in = t;
            }
            if (t >= (q.front().in + q.front().tU)) {
                delay += t - q.front().arr;
                outCount++;
                q.pop_front();
            }
        }
        t += step;
    }
    delay /= outCount;
    meanQlen /= static_cast<double>(num) / step;
    tau2 = tau1 / (m.size() - emptyP1);
    emptyP1 /= m.size();
    emptyP2 /= num;
    tau1 /= m.size();
}

void MM1::modelingv2(double in, double u, size_t num) {
    Random r;
    list<msg> q;
    vector<msg> m;
    size_t outCount = 0;
    delay = 0;
    meanQlen = 0;
    emptyP1 = 0;
    emptyP2 = 0;
    tau1 = 0;
    tau2 = 0;
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

    while (t < num) {
        /*if ((t * 100.0 / num) >= (percents + 1)) {
            percents++;
            cout << "\r" << percents << "%";
        }*/
        for (; it != m.end(); ++it) {
            if ((*it).arr < t) {
                if (q.empty()) {
                    emptyP1 += 1;
                } else {
                    tau1 += (q.front().in == 0 ? t : q.front().in) + q.front().tU - t;
                }
                q.push_back(*it);
            } else break;
        }
        if (q.empty()) {
            emptyP2 += step;
        }
        meanQlen += q.size();
        if (!q.empty()) {
            //t += q.front().tU;
            if (q.front().in == 0) {
                q.front().in = t;
            }
            if (t >= (q.front().in + q.front().tU)) {
                delay += t - q.front().arr;
                outCount++;
                q.pop_front();
            }
        }
        t += step;
    }
    delay /= outCount;
    meanQlen /= static_cast<double>(num) / step;
    tau2 = tau1 / (m.size() - emptyP1);
    emptyP1 /= m.size();
    emptyP2 /= num;
    tau1 /= m.size();
}
