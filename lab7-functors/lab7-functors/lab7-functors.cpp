/*
1.	Разработать функтор, позволяющий собирать статистику о последовательности целых чисел (послед может содержать числа от -500 до 500). Функтор после обработки последовательности алгоритмом for_each должен предоставлять следующую статистику:
a.	Максимальное число в последовательности
b.	Минимальное число в последовательности
c.	Среднее число в последовательности
d.	Количество положительных чисел
e.	Количество отрицательных чисел
f.	Сумму нечетных элементов последовательности
g.	Сумму четных элементов последовательности
h.	Совпадают ли первый и последний элементы последовательности.

Проверить работу программы на случайно сгенерированных последовательностях.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "Stat.h"

using namespace std;

int genRnd() { return (rand() % 1000) - 500; }
void print(int x) { cout << x << "\t"; }

int main()
{
    cout << "Hello World!\n";

    srand(time(0));

    vector<int> v(1000);
    generate(v.begin(), v.end(), genRnd);
    for_each(v.begin(), v.end(), print);
    cout << endl;
    Stat stat = for_each(v.begin(), v.end(), Stat(v[0]));
    cout << "Max val: " << stat.max << endl;
    cout << "Min val: " << stat.min << endl;
    cout << "Mid val: " << stat.mid() << endl;
    cout << "Positive: " << stat.pos << endl;
    cout << "Negative: " << stat.neg << endl;
    cout << "Odds: " << stat.odds << endl;
    cout << "Evens: " << stat.evens << endl;
    cout << "First and last equal: " << (stat.eqFL) << endl;
}
