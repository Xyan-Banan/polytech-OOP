#include <iostream>
#include <vector>
#include "Factorials.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    Factorials f;
    for (auto it = f.begin(); it != f.end(); it++) {
        cout << *it << endl;
    }

    auto it = f.end();
    for (it--; it != f.begin(); it--) {
        cout << *it << endl;
    }
    cout << *(f.begin()) << endl;

    vector<int> v;
    copy(f.begin(), f.end(), v.begin());

}
