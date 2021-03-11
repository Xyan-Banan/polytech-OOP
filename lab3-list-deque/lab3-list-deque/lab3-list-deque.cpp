#include <iostream>
#include "QueueWithPriority.h"

using namespace std;

int main()
{
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

}
