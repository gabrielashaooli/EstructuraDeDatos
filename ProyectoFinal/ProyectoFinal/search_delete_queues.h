#pragma once
#include <iostream>
#include "queue.h"

using namespace std;

inline void search_delete_queues(queue& queue_john, queue& queue_mary, queue& queue_peter, const int id)
{
	queue_john.delete_id(id);
	queue_mary.delete_id(id);
	queue_peter.delete_id(id);
}