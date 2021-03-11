#include <string>
#include <deque>

using namespace std;

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

#pragma once
class QueueWithPriority
{
public:
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
private:
    deque<pair<QueueElement,ElementPriority>> queue;
};

