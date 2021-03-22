/*
Необходимо выполнить ВСЕ задания.

1.	Ниже приведен интерфейс класса очереди с приоритетами, который функционирует следующим образом.

В очередь могут быть добавлены элементы, каждому элементу при добавлении присваивается один из трех уровней приоритета (low, normal, high)

Элементы из очереди извлекаются в соответствии с их приоритетами (сначала извлекаются элементы с приоритетом high, потом normal, потом low), элементы с одинаковыми приоритетами извлекаются из очереди в порядки их поступления.

В очереди также может происходить операция акселерации – все элементы с приоритетом low находящиеся в момент акселерации в очереди увеличивают свой приоритет до high и «обгоняют» элементы с приоритетом normal.

Ниже приведен интерфейс этого класса:
typedef enum
{
	LOW,
	NORMAL,
	HIGH
} ElementPriority;

typedef struct
{
	string name;
} QueueElement;

class QueueWithPriority
{
	// Конструктор, создает пустую очередь
   QueueWithPriority();

	// Деструктор
   ~QueueWithPriority();

	// Добавить в очередь элемент element с приоритетом priority
	void PutElementToQueue(const QueueElement& element, ElementPriority priority);

	// Получить элемент из очереди
	// метод должен возвращать элемент с наибольшим приоритетом, который был
	// добавлен в очередь раньше других
	QueueElement GetElementFromQueue();

	// Выполнить акселерацию
	void Accelerate();
};

Реализовать этот класс, используя list или deque. Объяснить свой выбор.
Протестируете программу, добавьте отладочный вывод, показывающий, что  класс работает правильно.

2.	Разработайте программу, которая
a.	Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений (обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
b.	Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.

Например если список содержит:
1 2 3 4 5 6 7 8
то вывод будет иметь вид
1 8 2 7 3 6 4 5

Подсказка: можно использовать рекурсию и двунаправленные итераторы

*/

//Соколов Михаил
//15.03.2021

#include <iostream>
#include <list>
#include <vector>
#include "QueueWithPriority.h"

using namespace std;

list<int> fillList(int size);
void printList(list<int> l);

int main()
{
	srand(time(0));
	cout << "Hello World!\n";
	QueueWithPriority queue;
	queue.PutElementToQueue(QueueElement{ "hello" }, ElementPriority::HIGH);
	queue.PutElementToQueue(QueueElement{ "world" }, ElementPriority::LOW);
	queue.PutElementToQueue(QueueElement{ "forest" }, ElementPriority::LOW);
	queue.PutElementToQueue(QueueElement{ "gump" }, ElementPriority::LOW);
	queue.PutElementToQueue(QueueElement{ "cup" }, ElementPriority::HIGH);
	queue.PutElementToQueue(QueueElement{ "speaker" }, ElementPriority::NORMAL);
	queue.PutElementToQueue(QueueElement{ "brush" }, ElementPriority::LOW);
	auto el = queue.GetElementFromQueue();
	cout << el.name << endl;
	el = queue.GetElementFromQueue();
	cout << el.name << endl;
	queue.Accelerate();
	el = queue.GetElementFromQueue();
	cout << el.name << endl;

	vector<int> sizes({ 0,1,2,3,4,5,7,14 });
	for (auto i = sizes.begin(); i != sizes.end(); i++) {
		list<int> l = fillList(*i);
		cout << "size: " << *i << endl;
		for (auto j = l.begin(); j != l.end(); j++)
			cout << *j << " ";
		cout << endl;
		printList(l);
		cout << endl;
	}
}

list<int> fillList(int size) {
	list<int> l;
	for (int i = 0; i < size; i++) {
		l.push_back(rand() % 21);
	}
	return l;
}

void printList(list<int> l) {
	if (l.size()) {
		auto itB = l.begin();
		auto itE = l.end();
		while (itB != itE && itB != --itE) {
			cout << *itB << " " << *itE << " ";
			itB++;
		}
		if (l.size() % 2 != 0) {
			cout << *itB << " ";
		}
	}
}

