#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <cstring>
using namespace std;
double enter();

int main() {
    int k;
    double x1, x2, approx, row, step;
    do {
        cout << "Enter x1" << endl;
        do {
            x1 = enter();
            if (x1 == 1) cout << "x1 can't be 1" << endl;
        } while (x1 == 1);
        cout << "Enter x2" << endl;
        do {
            x2 = enter();
            if (x2 <= x1) cout << "x2 can't be bigger than x1(or equal), please try again" << endl;
        } while (x2 <= x1);
        step = (x2 - x1) / 10.;
        for (int i = 0; i <= 10; i++)
        {
            approx = 0;
            k = 1;
            do {
                row = pow(-1, k + 1) * pow(x1, k) / k;
                approx += row;
                k++;
            } while (fabs(log(1 + x1) - approx) > 1e-6);
            cout << setiosflags(ios::fixed) << setprecision(6) << x1 << setprecision(6) << setw(10) << log(1 + x1)
                <<
                setw(10) << approx << setw(8) << k << resetiosflags(ios::fixed) << "   " << fabs(log(1 + x1) - approx)
                << endl;
            x1 += step;
        }
    } while (_getch() != 27);
    return 0;
}

double enter()
{
    double a;
    do {
        cin >> a;
        if (cin.fail() || a <= -1 || a > 1 || (fabs(a) < 1e-5 && a != 0))
        {
            //cout << a <<endl;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "You entered wrong data, please try again" << endl;
            continue;
        }
        char c[255];
        fgets(c, 256, stdin);
        if (strlen(c) > 1) {
            cout << "You entered wrong data, please try again" << endl;
            continue;
        }
        return a;
    } while (true);
}