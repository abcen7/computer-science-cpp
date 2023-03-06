#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

double get_value_of_func(double x) {
    return log(x) / 2;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    int n = 1;
    double x, sum_row = 0;
    double eps = 1e-24;
    double an;

    cout << "Введите X" << endl;
    cin >> x;

    cout << "Введите N" << endl;
    cin >> an;

    double an_func = an;
    double n_func = n;
    double sum_row_func = 0;
    double x_func = x;

    cout << "N Сумма ряда:" << endl;
    while (an > eps) {
        // Суда мы суем ряд
        an *= atan((x-1) / (x+1));
        sum_row += an;
        cout << n << " " << sum_row << "\n";
        ++n;
    }
    cout << "S(" << x << ") = " << sum_row << endl;

    cout << "N      Сумма ряда функции:\n";
    while (an_func > eps) {
        an_func *= atan((get_value_of_func(x_func) - 1) / get_value_of_func(x_func) + 1);
        sum_row_func += an_func;
        cout << n_func << "  " << sum_row_func << "\n";
        ++n_func;
    }
    cout << "S(" << x_func << ") = " << sum_row_func << endl;

    system("pause");
    return 0;
}