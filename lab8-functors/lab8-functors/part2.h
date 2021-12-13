/*
2.	Разработать программу, которая:
a.	Реализует иерархию геометрических фигур состоящую из:
i.	Класс Shape.
1.	Содержит информацию о положении центра фигуры (координаты x и y).
2.	Содердит метод IsMoreLeft, позволяющий определить расположена ли данная фигура левее (определяется по положению центра) чем фигура переданная в качестве аргумента
3.	Содердит метод IsUpper, позволяющий определить расположена ли данная фигура выше (определяется по положению центра) чем фигура переданная в качестве аргумента
4.	Определяет чисто виртаульную функцию рисования Draw (каждая фигура в реализации этой функци должна выводить на стандартный вывод свое название и положение цента)
ii.	Класс Circle производный от класса Shape
1.	Реализует Draw
iii.	Класс Triangle производный от класса Shape
1.	Реализует Draw
iv.	Класс Square производный от класса Shape
1.	Реализует Draw

b.	Содержит список list<Shape*>, заполенный указателями на различные фигуры

c.	С помощью стандартных алгоритмов и адаптеров выводит (Draw) все фигуры

d.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра слева-направо (имется в виду, что в начале списка должны идти фигуры находящиеся левее, координата x ) и выводит фигуры (Draw)

e.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра справа-налево и выводит фигуры

f.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра сверху-вниз и выводит фигуры

g.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра снизу-вверх и выводит фигуры
*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>
#include "Figures.h"
#pragma once

int genRnd() { return rand() % 20 - 10; }
Shape* genShape(int ind) {

	switch (ind)
	{
	case 0:
		return new Circle(genRnd(), genRnd());
		break;
	case 1:
		return new Triangle(genRnd(), genRnd());
		break;
	case 2:
		return new Square(genRnd(), genRnd());
		break;
	default:
		return new Shape(genRnd(), genRnd());
	}
}
Shape* genRndShape() {
	return genShape(rand() % 3);
}

int part2() {
	srand(time(0));
	list<Shape*> l(10);
	generate(l.begin(), l.end(), genRndShape);
	cout << "Original:" << endl;
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));

	cout << endl << "Left-to-Right:" << endl;
	l.sort(mem_fun(&Shape::LtR));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));

	cout << endl << "Right-to-Left:" << endl;
	l.sort(mem_fun(&Shape::RtL));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));

	cout <<endl<< "Up-to-Down:" << endl;
	l.sort(mem_fun(&Shape::UtD));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));

	cout << endl<<"Down-to-Up:" << endl;
	l.sort(mem_fun(&Shape::DtU));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));

	return 0;
}