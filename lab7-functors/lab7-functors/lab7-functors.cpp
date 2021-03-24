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
