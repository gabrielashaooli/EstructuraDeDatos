#include "list.h"
#include <iostream>
using namespace std;

list::list() { head_ = tail_ = temp_ = nullptr; }

list::~list()
{
	while (head_)
	{
		temp_ = head_;
		head_ = head_->next;
		delete temp_;
	}
}

void list::insert(const doctor& doc)
{
	temp_ = new node;
	temp_->data = doc;

	if (head_ == nullptr)
		head_ = tail_ = temp_;

	else
	{
		tail_->next = temp_;
		tail_ = temp_;
		tail_->next = nullptr;
	}
}

void list::show_full()
{
	if (is_empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	temp_ = head_;
	while (temp_->next != nullptr)
	{
		temp_->data.details();
		temp_ = temp_->next;
	}
	temp_->data.details();
}

bool list::is_empty() const
{
	return head_ == nullptr;
}