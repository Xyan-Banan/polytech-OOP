#include <iostream>

using namespace std;

#pragma once
class Shape
{
public:
	Shape() : x(0), y(0) {}
	Shape(int x, int y) :x(x), y(y) {}

	bool LtR(Shape* other) {
		return x < other->x;
	}

	bool RtL(Shape* other) {
		return x > other->x;
	}

	bool UtD(Shape* other) {
		return y > other->y;
	}

	bool DtU(Shape* other) {
		return y < other->y;
	}

	bool IsMoreLeft(Shape* other) { return LtR(other); }
	bool IsUpper(Shape* other) { return UtD(other); }
	virtual void Draw() { cout << "I'm a shape " << endl; }
protected:
	int x, y;
};

class Circle: public Shape
{
public:
	Circle(int x, int y): Shape(x,y){}
	void Draw() { cout << "Circle \t\tat \t(" << x << ", " << y << ")" << endl; }
private:

};

class Triangle : public Shape
{
public:
	Triangle(int x, int y) : Shape(x, y) {}
	void Draw() { cout << "Triangle \tat \t(" << x << ", " << y << ")" << endl; }
private:

};

class Square : public Shape
{
public:
	Square(int x, int y) : Shape(x, y) {}
	void Draw() { cout << "Square \t\tat \t(" << x << ", " << y << ")" << endl; }
private:

};
