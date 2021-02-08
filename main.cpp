#include <iostream>
#include <iomanip>
#include <fstream>
#include "src/MM1.h"

using namespace std;

double rule0(double rnd) {
    static Random r;
    rnd = r.rnd();
    return rnd;
}

double rule1(double rnd) {
    return 1 - rnd;
}

double rule2(double rnd) {
    return rnd;
}

int main() {
    MM1 m;
    size_t num = 1000000;
    ofstream outt("mm1_delay_t.dat");
    ofstream out0("mm1_delay_p.dat");
    ofstream out1("xx1_delay_p.dat");
    ofstream out2("x1-x1_delay_p.dat");

    ofstream outnt("mm1_mqlen_t.dat");
    ofstream outn0("mm1_mqlen_p.dat");
    ofstream outn1("xx1_mqlen_p.dat");
    ofstream outn2("x1-x1_mqlen_p.dat");

    ofstream oute0_1("mm1_emptyP1_p.dat");
    ofstream oute1_1("xx1_emptyP1_p.dat");
    ofstream oute2_1("x1-x1_emptyP1_p.dat");

    ofstream oute0_2("mm1_emptyP2_p.dat");
    ofstream oute1_2("xx1_emptyP2_p.dat");
    ofstream oute2_2("x1-x1_emptyP2_p.dat");

    ofstream outl0("mm1_delay_l_p.dat");
    ofstream outl1("xx1_delay_l_p.dat");
    ofstream outl2("x1-x1_delay_l_p.dat");
    double u = 1;
    for (double in = 0.1; in < 0.91; in += 0.1) {
        m.theory(in, u);
        m.theoryN(in, u);
        cout << fixed << setprecision(3) << in / u << " ::: " << m.getDelay() << " ::: ";
        outt << fixed << setprecision(3) << in / u << " " << m.getDelay() << endl;
        outnt << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() << endl;

        m.modelingv0(in, u, num);
        out0 << fixed << setprecision(3) << in / u << " " << m.getDelay() << endl;
        outn0 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() << endl;
        oute0_1 << fixed << setprecision(3) << in / u << " " << m.getEmptyP1() << endl;
        oute0_2 << fixed << setprecision(3) << in / u << " " << m.getEmptyP2() << endl;
        outl0 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() / in << endl;

        m.modelingv1(in, u, num);
        cout << fixed << setprecision(3) << m.getDelay() << " ::: ";
        out1 << fixed << setprecision(3) << in / u << " " << m.getDelay() << endl;
        outn1 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() << endl;
        oute1_1 << fixed << setprecision(3) << in / u << " " << m.getEmptyP1() << endl;
        oute1_2 << fixed << setprecision(3) << in / u << " " << m.getEmptyP2() << endl;
        outl1 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() / in << endl;

        m.modelingv2(in, u, num);
        cout << fixed << setprecision(3) << m.getDelay() << endl;
        out2 << fixed << setprecision(3) << in / u << " " << m.getDelay() << endl;
        outn2 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() << endl;
        oute2_1 << fixed << setprecision(3) << in / u << " " << m.getEmptyP1() << endl;
        oute2_2 << fixed << setprecision(3) << in / u << " " << m.getEmptyP2() << endl;
        outl2 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() / in << endl;

    }
}
