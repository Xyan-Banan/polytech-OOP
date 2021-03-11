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
    // �����������, ������� ������ �������
    QueueWithPriority();

    // ����������
    ~QueueWithPriority();

    // �������� � ������� ������� element � ����������� priority
    void PutElementToQueue(const QueueElement& element, ElementPriority priority);

    // �������� ������� �� �������
    // ����� ������ ���������� ������� � ���������� �����������, ������� ���
    // �������� � ������� ������ ������
    QueueElement GetElementFromQueue();

    // ��������� �����������
    void Accelerate();
private:
    deque<pair<QueueElement,ElementPriority>> queue;
};

