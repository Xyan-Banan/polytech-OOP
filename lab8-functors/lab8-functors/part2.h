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