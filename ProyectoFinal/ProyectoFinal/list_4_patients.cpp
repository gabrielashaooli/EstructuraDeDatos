#include "list_4_patients.h"
#include <iostream>
using namespace std;


list_4_patients::list_4_patients() { head_ = tail_ = temp_ = nullptr; }

list_4_patients::~list_4_patients()
{
	while (head_)
	{
		temp_ = head_;
		head_ = head_->next;
		delete temp_;
	}
}

void list_4_patients::insert(const patient& doc)
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

void list_4_patients::show_full() const
{
	if (is_empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	const node* temp = head_;
	while (temp != nullptr)
	{
		temp->data.details();
		temp = temp->next;
	}
}

bool list_4_patients::is_empty() const
{
	return head_ == nullptr;
}


void list_4_patients::delete_id(const int id)
{
	if (is_empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	node* current = head_;
	node* previous = nullptr;
	while (current != nullptr)
	{
		if (current->data.id == id)
		{
			if (current == head_)
			{
				head_ = head_->next;
				delete current;
				return;
			}
			if (current == tail_)
			{
				tail_ = previous;
				tail_->next = nullptr;
				delete current;
				return;
			}
			previous->next = current->next;
			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}

	cout << "ID not found" << endl;
}

patient list_4_patients::get_head() const
{
	return head_->data;
}

void list_4_patients::pop_front()
{
	if (is_empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	const node* temp = head_;
	if (head_ == tail_)
		head_ = tail_ = nullptr;
	else
		head_ = head_->next;
	delete temp;
}

void list_4_patients::show_urgent() const
{
	if (is_empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Urgent Patients" << endl;
	const node* temp = head_;
	while (temp != nullptr)
	{
		if (temp->data.urgency == 1)
			temp->data.details();
		temp = temp->next;
	}
}