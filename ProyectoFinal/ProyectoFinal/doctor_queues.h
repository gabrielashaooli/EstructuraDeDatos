#pragma once
#include <iostream>
#include "queue.h"
using namespace std;

enum doctor_queues
{
	back = 0,
	see_john,
	see_mary,
	see_peter
};

inline void doctor_queues(const queue& queue_john, const queue& queue_mary, const queue& queue_peter)
{
	cout << "Available queues:" << endl;
	cout << "1. John" << endl;
	cout << "2. Mary" << endl;
	cout << "3. Peter" << endl;
	cout << "0. EXIT" << endl;

	int choice;
	cout << "Choice: ";
	cin >> choice;

	switch (choice)
	{
	case see_john:
		queue_john.show();
		break;

	case see_mary:
		queue_mary.show();
		break;

	case see_peter:
		queue_peter.show();
		break;

	case back:
		cout << "Exiting..." << endl;
		break;

	default:
		cout << "Invalid choice" << endl;
		break;
	}
}