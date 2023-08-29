#pragma once
#include "doctor.h"

class list
{
public:
	list();
	~list();

	void insert(const doctor&);
	void show_full();
	bool is_empty() const;

private:
	struct node
	{
		doctor data;
		node* next{};
	};

	node* head_, * tail_, * temp_;
};