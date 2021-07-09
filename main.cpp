#include <iostream>
#include <iomanip>
#include <fstream>
#include "src/MM1.h"
#include "src/Random.h"

using namespace std;

int main() {
    MM1 m;
    size_t num = 100000;
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

    ofstream outt0("mm1_tau1_p.dat");
    ofstream outt1("xx1_tau1_p.dat");
    ofstream outt2("x1-x1_tau1_p.dat");

    ofstream outt20("mm1_tau2_p.dat");
    ofstream outt21("xx1_tau2_p.dat");
    ofstream outt22("x1-x1_tau2_p.dat");

    ofstream outnin0("mm1_nin_p.dat");
    ofstream outnin1("xx1_nin_p.dat");
    ofstream outnin2("x1-x1_nin_p.dat");

    ofstream outnout0("mm1_nout_p.dat");
    ofstream outnout1("xx1_nout_p.dat");
    ofstream outnout2("x1-x1_nout_p.dat");

    ofstream outtu0("mm1_tu_p.dat");
    ofstream outtu1("xx1_tu_p.dat");
    ofstream outtu2("x1-x1_tu_p.dat");

    ofstream outT10("mm1_T1_p.dat");
    ofstream outT11("xx1_T1_p.dat");
    ofstream outT12("x1-x1_T1_p.dat");

    ofstream outT20("mm1_T2_p.dat");
    ofstream outT21("xx1_T2_p.dat");
    ofstream outT22("x1-x1_T2_p.dat");

    double u = 1;


    for (double in = 0.1; in < 0.91; in += 0.1) {
        double cov1 = 0;
        double cov2 = 0;
        Random r;

        m.theory(in, u);
        m.theoryN(in, u);
        cout << fixed << setprecision(3) << in / u << " ::: " << m.getDelay() << " ::: ";
        outt << fixed << setprecision(3) << in / u << " " << m.getDelay() << endl;
        outnt << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() << endl;

        m.modeling(in, u, num, 0);
        out0 << fixed << setprecision(3) << in / u << " " << m.getDelay() << endl;
        outn0 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() << endl;
        oute0_1 << fixed << setprecision(3) << in / u << " " << m.getEmptyP1() << endl;
        oute0_2 << fixed << setprecision(3) << in / u << " " << m.getEmptyP2() << endl;
        outl0 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() / in << endl;
        outt0 << fixed << setprecision(3) << in / u << " " << m.getTau1() << endl;
        outt20 << fixed << setprecision(3) << in / u << " " << m.getTau2() << endl;
        outnin0 << fixed << setprecision(3) << in / u << " " << m.getNIn() << endl;
        outnout0 << fixed << setprecision(3) << in / u << " " << m.getNOut() << endl;
        outtu0 << fixed << setprecision(3) << in / u << " " << m.getMeanTU() << endl;
        outT10 << fixed << setprecision(3) << in / u << " " << m.getT1() << endl;
        outT20 << fixed << setprecision(3) << in / u << " " << m.getT2() << endl;

        m.modeling(in, u, num, 1);
        cout << fixed << setprecision(3) << m.getDelay() << " ::: ";
        out1 << fixed << setprecision(3) << in / u << " " << m.getDelay() << endl;
        outn1 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() << endl;
        oute1_1 << fixed << setprecision(3) << in / u << " " << m.getEmptyP1() << endl;
        oute1_2 << fixed << setprecision(3) << in / u << " " << m.getEmptyP2() << endl;
        outl1 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() / in << endl;
        outt1 << fixed << setprecision(3) << in / u << " " << m.getTau1() << endl;
        outt21 << fixed << setprecision(3) << in / u << " " << m.getTau2() << endl;
        outnin1 << fixed << setprecision(3) << in / u << " " << m.getNIn() << endl;
        outnout1 << fixed << setprecision(3) << in / u << " " << m.getNOut() << endl;
        outtu1 << fixed << setprecision(3) << in / u << " " << m.getMeanTU() << endl;
        outT11 << fixed << setprecision(3) << in / u << " " << m.getT1() << endl;
        outT21 << fixed << setprecision(3) << in / u << " " << m.getT2() << endl;

        m.modeling(in, u, num, 2);
        cout << fixed << setprecision(3) << m.getDelay() << endl;
        out2 << fixed << setprecision(3) << in / u << " " << m.getDelay() << endl;
        outn2 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() << endl;
        oute2_1 << fixed << setprecision(3) << in / u << " " << m.getEmptyP1() << endl;
        oute2_2 << fixed << setprecision(3) << in / u << " " << m.getEmptyP2() << endl;
        outl2 << fixed << setprecision(3) << in / u << " " << m.getMeanQlen() / in << endl;
        outt2 << fixed << setprecision(3) << in / u << " " << m.getTau1() << endl;
        outt22 << fixed << setprecision(3) << in / u << " " << m.getTau2() << endl;
        outnin2 << fixed << setprecision(3) << in / u << " " << m.getNIn() << endl;
        outnout2 << fixed << setprecision(3) << in / u << " " << m.getNOut() << endl;
        outtu2 << fixed << setprecision(3) << in / u << " " << m.getMeanTU() << endl;
        outT12 << fixed << setprecision(3) << in / u << " " << m.getT1() << endl;
        outT22 << fixed << setprecision(3) << in / u << " " << m.getT2() << endl;
    }
}