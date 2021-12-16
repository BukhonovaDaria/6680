#include <Windows.h>
#include <iostream>
#include "stdio.h"
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double c = 0, n;
    cout << " Введите кол-во членов посл-ти (n > 0) n = ";
    cin >> n;
    bool firfirtest = true;
    while (n <= 0 || n != int(n) || !firfirtest == cin.good()) {
        cout << "\n Введите кол-во членов посл-ти (n > 0) n = ";
        cin >> n;
    }
    while (c == 0) {
        cout << "\n Выберите необходимое действие:\n 1. Задание 1\n 2. Задание 2\n 3. Завершить работу\n\n Введите выбранное число: ";
        cin >> c;
        bool firtest = true;
        while (c < 1 || c>3 || c != int(c) || !firtest == cin.good()) {
            cout << "\n Вы ввели некорректные данные.\n Введите целое число от 1 до 3 : ";
            cin >> c;
        }
        if (c == 1) {
            double x;
            bool test = true;
            do {
                cout << " Введите x для нахождения частичной суммы ряда\n Чтобы найти значение ф-ии arcsinx\n Введите х в интервале (-1;1) x = ";
                cin >> x;
                if (!test == cin.good() || x > 1 || x < -1) {
                    cout << "\n Ошибка ввода\n";
                }
                else
                    test = false;
            } while (test);
            double a, m, h, t;
            double f = 0;
            a = x;
            h = -1;
            t = 1;
            double sum1 = 1;
            double sum = 0;
            for (int i = 1; i < n; i++) {
                sum1 += 2;
                h += 2;
                f += 2;
                t *= h / f;
                a *= pow(x, 2);
                m = t * (a / sum1);
                sum += m;
            }
            double s;
            s = x + sum;
            cout << "\n Сумма ряда s = " << setprecision(11) << s << " \n";
            double r;
            r = asin(x) - s;
            cout << " Абсолютная погрешность равна r = " << abs(r) << "\n";
            double p = t * (a / sum1);
            cout << " Абсолютная величина последнего слагаемого p = " << abs(p) << "\n\n";
            if (abs(r) > abs(p)) {
                cout << " Абсолютная погрешность больше абсолютной величины последнего слагаемого\n";
            }
            else if (abs(p) > abs(r)) {
                cout << " Абсолютная величина последнего слагаемого больше абсолютной погрешности\n";
            }
            else cout << " Абсолютная погрешность равна абсолютной величине последнего слагаемого\n";
            c = 0;
        }
        else if (c == 2) {

            double x, E;
            bool test = true;
            cout << "\n Задайте точность вычисления Е = ";
            cin >> E;
            do {
                cout << " Введите x для нахождения частичной суммы ряда (x > 1) x = ";
                cin >> x;
                if (!test == cin.good() || x == 0) {
                    cout << "\n Ошибка ввода\n";
                }
                else
                    test = false;
            } while (test);
            double a, h, t;
            double f = 0;
            a = x;
            h = -1;
            t = 1;
            double sum1 = 1;
            double summ = 0;
            double sum = 0, sum2 = 0, k = 0, d = 0;
            for (int i = 1; i < n; i++) {
                sum1 += 2;
                h += 2;
                f += 2;
                t *= h / f;
                a *= pow(x, 2);
                summ = t * (a / sum1);
                if (abs(summ) > E) {
                    sum += summ;
                    k++;
                }
                if (abs(summ) > E * 10) {
                    sum2 += summ;
                    d++;
                }
            }
            if ((sum != 0) && (sum2 != 0)) {
                if (x > E) {
                    sum = x + sum;
                    sum2 = x + sum2;
                    k++;
                    d++;
                }
                cout << "\n Сумма элементов больших чем Е равна sum = " << sum << "\n Кол-во таких элементов k = " << k << "\n\n";
                cout << " Сумма элементов больших чем Е*10 (Е увеличенно на порядок) равна sum2 = " << sum2 << "\n Кол-во таких элементов d = " << d << "\n\n";
            }
            else if ((sum != 0) && (sum2 == 0)) {
                if (x > E * 10) {
                    sum = x + sum;
                    sum2 = x + sum2;
                    k++;
                    d++;
                    cout << "\n Сумма элементов больших чем Е равна sum = " << sum << "\n Кол-во таких элементов k = " << k << "\n\n";
                    cout << " Сумма элементов больших чем Е*10 (Е увеличенно на порядок) равна sum2 = " << sum2 << "\n Кол-во таких элементов d = " << d << "\n\n";
                }
                else if (x > E) {
                    sum = x + sum;
                    cout << "\n Сумма элементов больших чем Е равна sum = " << sum << "\n Кол-во таких элементов k = " << k << "\n\n";
                    cout << " Элементов больших чем Е*10 (E увеличенно на порядок) не найдено\n\n";
                }
            }
            else if ((sum == 0) && (sum2 == 0)) {
                if (x > E * 10) {
                    sum = sum2 = 1;
                    k = d = 1;
                    cout << "\n Сумма элементов больших чем Е равна sum = " << sum << "\n Кол-во таких элементов k = " << k << "\n\n";
                    cout << " Сумма элементов больших чем Е*10 (Е увеличенно на порядок) равна sum2 = " << sum2 << "\n Кол-во таких элементов d = " << d << "\n\n";
                }
                else if (x > E) {
                    sum = 1;
                    k = 1;
                    cout << "\n Сумма элементов больших чем Е равна sum = " << sum << "\n Кол-во таких элементов k = " << k << "\n\n";
                    cout << " Элементов больших чем Е*10 (E увеличенно на порядок) не найдено\n\n";
                }
                else
                    cout << "\n Элементов больших чем Е и Е*10 (увеличенного на порядок) не найдено\n\n";
            }
            c = 0;
        }
        else if (c == 3) {
            return 0;
        }
    }
}