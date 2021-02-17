#include <iostream>
#include <iomanip>
#include <fstream>
#include "src/MM1.h"

using namespace std;

int main() {
    MM1 m;
    size_t num = 100000;

    ofstream outn0("mm1_mqlen_p.dat");
    ofstream outn1("xx1_mqlen_p.dat");
    ofstream outn2("x1-x1_mqlen_p.dat");

    double u = 1;
    for (double in = 0.1; in < 0.91; in += 0.1) {

        cout << in << endl;

        m.modeling(in, u, num, 0);
        outn0 << fixed << setprecision(3) << in / u << " " << m.getMeanQLen() << endl;

        m.modeling(in, u, num, 1);
        outn1 << fixed << setprecision(3) << in / u << " " << m.getMeanQLen() << endl;

        m.modeling(in, u, num, 2);
        outn2 << fixed << setprecision(3) << in / u << " " << m.getMeanQLen() << endl;
    }
}
