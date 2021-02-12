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
    size_t num = 10000;
    ofstream outn0("mm1_mqlen_p.dat");
    ofstream outn1("xx1_mqlen_p.dat");
    ofstream outn2("x1-x1_mqlen_p.dat");

    double u = 1;
    for (double in = 0.1; in < 0.91; in += 0.1) {

        m.modeling(in, u, num);
        outn0 << fixed << setprecision(3) << in / u << " " << m.getMeanQLen() << endl;

        outn1 << fixed << setprecision(3) << in / u << " " << m.getMeanQLen() << endl;

        outn2 << fixed << setprecision(3) << in / u << " " << m.getMeanQLen() << endl;
    }
}
