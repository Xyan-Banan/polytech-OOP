/*
2.	Ќаписать программу, котора€ выполн€ет следующие действи€ (все операции должны выполн€тьс€ с помощью стандартных алгоритмов):
a.	«аполн€ет вектор геометрическими фигурами. √еометрическа€ фигура может быть треугольником, квадратом, пр€моугольником или п€ти угольником. —труктура описывающа€ геометрическую фигуру  определена ниже,
b.	ѕодсчитывает общее количество вершин всех фигур содержащихс€ в векторе (так треугольник добавл€ет к общему числу 3, квадрат 4 и т.д.)
c.	ѕодсчитывает количество треугольников, квадратов и пр€моугольников в векторе
d.	”дал€ет все п€тиугольники
e.	Ќа основании этого вектора создает vector<Point>, который содержит координаты одной из вершин (любой) каждой фигуры, т.е. первый элемент этого вектора содержит координаты одной из вершину первой фигуры, второй элемент этого вектора содержит координаты одной из вершину второй фигуры и т.д.
f.	»змен€ет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом пр€моугольники.
g.	–аспечатывает вектор после каждого этапа работы
*/

#pragma once
#include <vector>
using namespace std;

typedef struct
{
	int x, y;
} Point;

typedef  struct
{
	int vertex_num;
	vector<Point> vertexes;
} Shape;

Shape genShape();
//vector<Shape> fillVector(int size);
bool isSquare(Shape s);
void printShape(Shape s);
//void printVector(vector<Shape>& v);
//int countVertexes(vector<Shape>& v);
//vector<int> countShapes(vector<Shape>& v);
//void removePentagons(vector<Shape>& v);
//vector<Point> getPoints(vector<Shape>& v);
//void processVector(vector<Shape>& v);

class counter
{
public:
	counter() :sum(0) {}
	void operator() (Shape s)
	{
		sum += s.vertex_num;
	}

	int get_sum()
	{
		return sum;
	}

private:
	int sum;
};


int part2() {
	srand(time(0));
	vector<Shape> v(10);
	generate(v.begin(), v.end(), genShape);
	for_each(v.begin(), v.end(), printShape);
	
	cout << "Number of vertexes: " << for_each(v.begin(),v.end(),counter()).get_sum() << endl;
	
	cout << "Number of triangles: " << count_if(v.begin(), v.end(), [](Shape s) {return s.vertex_num == 3; }) << endl;
	cout << "Number of rectangles: " << count_if(v.begin(), v.end(), [](Shape s) {return s.vertex_num == 4; }) << endl;
	cout << "Number of pentagons: " << count_if(v.begin(), v.end(), [](Shape s) {return s.vertex_num == 5; }) << endl;
	
	cout << "Removing pentagons" << endl;
	auto new_end = remove_if(v.begin(), v.end(), [](Shape s) {return s.vertex_num == 5; });
	v.erase(new_end, v.end());
	for_each(v.begin(), v.end(), printShape);
	
	vector<Point> points(v.size());
	transform(v.begin(), v.end(), points.begin(), [](Shape s) { return s.vertexes[0]; });
	cout << "First points of each figure:" << endl;
	for_each(points.begin(), points.end(), [](Point p) { cout << "(" << p.x << ", " << p.y << ")" << endl; });
	
	cout << "Processing vector" << endl;
	auto p = partition(v.begin(), v.end(), [](Shape s) {return s.vertex_num == 3; });
	partition(p, v.end(), isSquare);
	for_each(v.begin(), v.end(), printShape);

	return 0;
}

Shape genShape() {
	Shape figure;
	int sides = 3 + rand() % 3;
	figure.vertex_num = sides;
	for (int i = 0; i < sides; i++) {
		figure.vertexes.push_back(Point{ rand() % 20 - 10,rand() % 20 - 10 });
	}
	return figure;
}

void printShape(Shape s) {
	cout << s.vertex_num << " ";
	for (int j = 0; j < s.vertex_num; j++) {
		cout << "(" << s.vertexes[j].x << ", " << s.vertexes[j].y << ") ";
	}
	cout << endl;
}

bool isSquare(Shape s) {
	vector<Point> points = s.vertexes;
	if (points.size() != 4)
		return false;

	Point sides1 = { points[2].x - points[0].x, points[2].y - points[0].y };
	double diag1 = sqrt(pow(sides1.x, 2) + pow(sides1.y, 2));
	Point sides2 = { points[3].x - points[1].x, points[3].y - points[1].y };
	double diag2 = sqrt(pow(sides2.x, 2) + pow(sides2.y, 2));

	if (diag1 != diag2) {
		return false;
	}

	if (sides1.x == 0 || sides2.x == 0)
		return false;

	double m1 = (double)sides1.y / sides1.x;
	double m2 = (double)sides2.y / sides2.x;
	if (m1 == -1 / m2){
		cout << "it's a square!" << endl;
		printShape(s);
		return true;
	}
	return false;
}

/*
void processVector(vector<Shape>& v) {
	vector<Shape> res;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].vertex_num == 3) {
			res.push_back(v[i]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].vertex_num == 4 && isSquare(v[i])) {
			//cout << res.size() << " it's a square!" << endl;
			//printShape(v[i]);
			res.push_back(v[i]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].vertex_num == 4 && !isSquare(v[i])) {
			res.push_back(v[i]);
		}
	}

	v = res;
}

vector<Point> getPoints(vector<Shape>& v) {
	vector<Point> res;
	for (int i = 0; i < v.size(); i++) {
		res.push_back(v[i].vertexes[0]);
	}
	return res;
}

void removePentagons(vector<Shape>& v) {
	int i = 0;
	while (i < v.size()) {
		if (v[i].vertex_num == 5) {
			v.erase(v.begin() + i);
		}
		else {
			i++;
		}
	}
}

vector<int> countShapes(vector<Shape>& v) {
	vector<int> counters({ 0,0,0 });
	for (int i = 0; i < v.size(); i++) {
		counters[v[i].vertex_num - 3]++;
	}
	return counters;
}

int countVertexes(vector<Shape>& v) {
	int s = 0;
	for (int i = 0; i < v.size(); i++) {
		s += v[i].vertex_num;
	}
	return s;
}


void printVector(vector<Shape>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << i << " ";
		printShape(v[i]);
		cout << endl;
	}

}

vector<Shape> fillVector(int size) {
	vector<Shape> v;
	for (int i = 0; i < size; i++) {
		v.push_back(genShape());
	}
	return v;
}
*/
