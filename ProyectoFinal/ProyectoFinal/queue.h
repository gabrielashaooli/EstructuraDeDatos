#pragma once
#include "patient.h"

struct node
{
	patient data;
	node* next{};
};

class queue
{
public:
	queue();
	~queue();
	void enqueue(patient);
	patient dequeue();

	void show() const;
	bool is_empty() const;
	int size() const;
	void delete_id(int);
	void clear();

private:
	node* head_;
	node* tail_;
};