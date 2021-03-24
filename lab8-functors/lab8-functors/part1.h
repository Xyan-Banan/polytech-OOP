#include <iostream>
#include <vector>
#include <algorithm>

# define M_PI           3.14159265358979323846

#pragma once

using namespace std;

double rndDouble() { return (double)rand() / rand(); }
void print(double x) { cout << x << endl; }
double mulPi(double d) { return d * M_PI; }

int part1() {

    srand(time(0));
    vector<double> v(10);
    generate(v.begin(), v.end(), rndDouble);
    for_each(v.begin(), v.end(), print);
    cout << "______________________" << endl;
    transform(v.begin(), v.end(), v.begin(), mulPi);
    for_each(v.begin(), v.end(), print);

    return 0;
}