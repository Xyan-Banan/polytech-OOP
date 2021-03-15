#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void fillVector(vector<int>& v, int nValues);
void printVector(vector<int> v);
void sortP1(vector<int>& v);
void sortP2(vector<int>& v);
void sortP3(vector<int>& v);
int* readArray(ifstream& file, int size);
void readVector(vector<int>& v);
void processVector(vector<int>& v);
void fillRandom(double* arr, int size);
void sortP6(double* v, int size);


int main()
{
    srand(time(0));

    vector<int> v;
    fillVector(v, 10);
    vector<int> v1 = v;
    cout << "Original vector:" << endl;
    printVector(v1);

    /////////////////// P1 ///////////////////
    sortP1(v1);
    cout << "Sorted with operator[]:" << endl;
    printVector(v1);

    /////////////////// P2 ///////////////////
    v1 = v;
    sortP2(v1);
    cout << "Sorted with method at():" << endl;
    printVector(v1);

    /////////////////// P3 ///////////////////
    v1 = v;
    sortP3(v1);
    cout << "Sorted with iterators:" << endl;
    printVector(v1);

    /////////////////// P4 ///////////////////
    cout << "Reading values to array from file:" << endl;
    ifstream file;
    file.open("array.txt");
    if (!file) {
        cout << "File array.txt could not be opened" << endl;
    }
    else {
        int size;
        file >> size;
        int* arr = readArray(file, size);

        cout << "Read from file:" << endl;
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;

        v1.insert(v1.begin(), arr, arr + size);
        //copy(arr,arr + size,v1.begin());

        cout << "Copied values from array:" << endl;
        printVector(v1);
    }

    /////////////////// P5 ///////////////////
    
    /*readVector(v1);
    processVector(v1);
    cout << "Processed vector:" << endl;
    printVector(v1);*/

    /////////////////// P6 ///////////////////

    const int size = 10;
    double doubles[size];
    fillRandom(doubles,size);
    cout << "Random doubles" << endl;
    for (int i = 0; i < size; i++) {
        cout << doubles[i] << " ";
    }
    cout << endl;
    sortP6(doubles, size);
    cout << "Sorted array of doubles" << endl;
    for (int i = 0; i < size; i++) {
        cout << doubles[i] << " ";
    }
    cout << endl;

    return 0;
}

void fillVector(vector<int>& v, int nValues) {
    for (int i = 0; i < nValues; i++) {
        v.push_back(rand() % 10);
    }
}

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void sortP1(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        bool swapped = false;
        for (int j = 0; j < v.size() - i - 1; j++)
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        if (!swapped)
            break;
    }
}

void sortP2(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        bool swapped = false;
        for (int j = 0; j < v.size() - i - 1; j++)
            if (v.at(j) > v.at(j + 1)) {
                swap(v.at(j), v.at(j + 1));
                swapped = true;
            }
        if (!swapped)
            break;
    }
}

void sortP3(vector<int>& v) {
    vector<int>::iterator itI;
    
    for (itI = v.end() - 1; itI != v.begin(); itI--) {
        bool swapped = false;
        vector<int>::iterator itJ;
        for (itJ = v.begin(); itJ != itI; itJ++)
            if (*itJ > *(itJ + 1)) {
                swap(*itJ, *(itJ + 1));
                swapped = true;
            }
        if (!swapped)
            break;
    }
}

int* readArray(ifstream& file, int size) {
    int* arr = new int[size];
    for (int i = 0; i < size && !file.eof(); i++) {
        file >> arr[i];
    }
    return arr;
}

void readVector(vector<int>& v) {
    v.clear();
    cout << "Enter some values (enter 0 to end)" << endl;
    int input;
    cin >> input;
    while (input != 0) {
        v.push_back(input);
        cin >> input;
    }
}

void processVector(vector<int>& v) {
    if (v.empty())
        return;

    vector<int>::iterator it;
    vector<int> resV;
    if (v.back() == 1) {
        //_Erase_nodes_if(v, [](int x) { return x % 2 == 0; });

        for (it = v.begin(); it != v.end(); ++it) {
            if (*it % 2 != 0) {
                resV.push_back(*it);
                //v.erase(it);
            }
        }
    }
    else if (v.back() == 2) {
        for (it = v.begin(); it != v.end(); it++) {
            if (*it % 3 == 0) {
                resV.push_back(*it);
                resV.insert(resV.end(), 3, 1);
            }
            else
                resV.push_back(*it);
        }
    }
    v = resV;
}

void fillRandom(double* arr, int size) {
    int eps = 1000;
    double x;
    for (int i = 0; i < size; i++) {
        x = (double)(rand() % (2 * (eps + 1)) - eps) / eps;
        arr[i] = x;
    }
}

void sortP6(double* v, int size) {
    for (int i = 0; i < size; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        if (!swapped)
            break;
    }
}