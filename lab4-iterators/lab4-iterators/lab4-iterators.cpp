﻿/*
Реализуйте следующие классы
•	Контейнер, который содержит значения факториала от 1! до 10!.

Интерфейс класса должен включать в себя как минимум:
o	Конструктор по умолчанию
o	Функцию получения итератора указывающего на первый элемент контейнера - begin()
o	Функцию получения итератора указывающего на элемент, следующий за последним - end()

Доступ к элементам этого контейнера возможен только с помощью итераторов возвращаемых функциями begin() и end().

Контейнер не должен содержать в памяти свои элементы, они должны вычисляться при обращении к ним через итератор

•	Класс итератора для перечисления элементов этого контейнера, объекты этого класса возвращаются функциями begin() и end(). Итератор должен быть двунаправленным. Итератор должен быть совместимым с STL (проверить это можно используя алгоритм copy для копирования содержимого разработанного контейнера в vector<int>)


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "Factorials.h"

using namespace std;

int main()
{
	cout << "Hello World!\n";
	cout << "Direct order" << endl;
	Factorials f;
	for (auto it = f.begin(); it != f.end(); ++it) {
		cout << *it << endl;
	}

	cout << endl << "Reverse order" << endl;
	auto it = f.end();
	for (it--; it != f.begin(); it--) {
		cout << *it << endl;
	}
	cout << *(f.begin()) << endl;

	vector<int> v(10);
	copy(f.begin(), f.end(), v.begin());
	cout << endl << "Copied to vector" << endl;
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

}
