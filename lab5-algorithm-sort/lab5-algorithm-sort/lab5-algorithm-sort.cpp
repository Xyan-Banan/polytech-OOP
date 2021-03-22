/*
Выполнить ВСЕ задания

1.	Написать программу, которая выполняет следующие действия:

a.	Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, генерируются случайным образом в диапазоне от -5 до 5, str заполняется из таблицы (таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
b.	Выводит полученный вектор на печать
c.	Сортирует вектор следующим образом:
i.	По возрастанию key1
ii.	Если key1 одинаковые, то по возрастанию key2
iii.	Если key1 и key2 одинаковые, то по возрастанию длинны строки str
d.	Выводит полученный вектор на печать

DataStruct определена следующим образом:
typedef struct
{
    int       key1;
    int       key2;
    string  str;
} DataStruct;

*/

//Соколов Михаил
//22.03.2021

#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int key1;
	int key2;
	string str;
} DataStruct;

vector<DataStruct> fillVector(int size);
void printVector(vector<DataStruct>& v);
void quickSort(vector<DataStruct>& v, int start, int end);

int main()
{
	srand(time(0));
	vector<DataStruct> v = fillVector(20);
	printVector(v);
	quickSort(v, 0, v.size() - 1);
	cout << "_____________________________________" << endl;

	printVector(v);
}

int compare(DataStruct d1, DataStruct d2) {
	if (d1.key1 > d2.key1)
		return 1;
	else if (d1.key1 == d2.key1) {
		if (d1.key2 > d2.key2)
			return 1;
		else if (d1.key2 == d2.key2) {
			if (d1.str.size() > d2.str.size())
				return 1;
			else if (d1.str.size() == d2.str.size()) {
				return 0;
			}
		}
	}
	return -1;
}

int partition(vector<DataStruct>& v, int start, int end) {
	DataStruct pivot = v.at((start + end) / 2);
	int i = start;
	int j = end;
	while (true) {
		while (compare(v.at(i), pivot) < 0)
			i++;
		while (compare(v.at(j), pivot) > 0)
			j--;
		if (i >= j)
			return j;
		swap(v.at(i), v.at(j));
		i++;
		j--;
	}
}

void quickSort(vector<DataStruct>& v, int start, int end) {
	if (start < end) {
		int p = partition(v, start, end);
		quickSort(v, start, p);
		quickSort(v, p + 1, end);
	}
}

void printVector(vector<DataStruct>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i).key1 << "\t" << v.at(i).key2 << "\t" << v.at(i).str << endl;
	}
}

vector<DataStruct> fillVector(int size) {
	vector<string> strings({ "cup", "light", "kendle", "ice", "pen", "batman", "star", "water", "guitar", "frost" });

	vector<DataStruct> v;

	for (int i = 0; i < size; i++) {
		v.push_back(DataStruct{ rand() % 10 - 5,rand() % 11 - 5 , strings.at(rand() % strings.size()) });
	}

	return v;
}
