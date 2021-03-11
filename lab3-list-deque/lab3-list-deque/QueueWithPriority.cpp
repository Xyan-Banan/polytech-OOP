#include "QueueWithPriority.h"

QueueWithPriority::QueueWithPriority() {
	queue = deque<pair<QueueElement, ElementPriority>>();
}

QueueWithPriority::~QueueWithPriority() {
	queue.clear();
}

void QueueWithPriority::PutElementToQueue(const QueueElement& element, ElementPriority priority) {
	queue.push_back(make_pair(element, priority));
}

QueueElement QueueWithPriority::GetElementFromQueue() {
	if (queue.size() == 0) {
		throw exception("Queue is empty");
	}
	
	if (queue.size() == 1) {
		auto res = queue.front().first;
		queue.pop_front();
		return res;
	}

	auto res = queue.front();
	auto resIt = queue.begin();
	for (auto it = queue.begin() + 1; it != queue.end() && res.second != ElementPriority::HIGH; it++) {
		if ((*it).second > res.second) {
			res = *it;
			resIt = it;
		}
	}

	queue.erase(resIt);
	return res.first;
}

void QueueWithPriority::Accelerate() {
	if (queue.size() == 0) {
		return;
	}

	for (auto it = queue.begin(); it != queue.end(); it++) {
		if ((*it).second == ElementPriority::LOW) {
			(*it).second = ElementPriority::HIGH;
		}
	}
}