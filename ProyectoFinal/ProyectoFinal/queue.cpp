#include "queue.h"

#include <utility>

using namespace std;

queue::queue()
{
	head_ = nullptr;
	tail_ = nullptr;
}

queue::~queue()
{
	const node* current = head_;
	while (current != nullptr)
	{
		const node* next = current->next;
		delete current;
		current = next;
	}
}

void queue::enqueue(patient new_)
{
	const auto new_node = new node;
	new_node->data = move(new_);
	new_node->next = nullptr;

	if (head_ == nullptr)
	{
		head_ = new_node;
		tail_ = new_node;
	}
	else
	{
		tail_->next = new_node;
		tail_ = new_node;
	}
}

patient queue::dequeue()
{
	if (head_ == nullptr) return patient{};

	const auto old_head = head_;
	const auto old_data = old_head->data;
	head_ = old_head->next;
	delete old_head;

	return old_data;
}


void queue::show() const
{
	if (is_empty())
	{
		cout << "Queue is empty" << endl;
		return;
	}

	const node* current = head_;
	while (current->next != nullptr)
	{
		current->data.details();
		current = current->next;
	}
	current->data.details();
}

bool queue::is_empty() const
{
	return head_ == nullptr;
}

int queue::size() const
{
	int size = 0;
	const node* current = head_;
	while (current != nullptr)
	{
		size++;
		current = current->next;
	}
	return size;
}

void queue::delete_id(const int id)
{
	int count = 0;
	while (count < size())
	{
		patient temp = dequeue();
		count++;
		if (temp.get_id() != id)
		{
			enqueue(temp);
		}
	}
}

void queue::clear()
{
	const node* current = head_;
	while (current != nullptr)
	{
		const node* next = current->next;
		delete current;
		current = next;
	}
	head_ = nullptr;
	tail_ = nullptr;
}