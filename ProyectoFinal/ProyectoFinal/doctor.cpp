#include "doctor.h"
#include <iostream>
using namespace std;

doctor::doctor() = default;

doctor::doctor(string name, const int age, const int dr_id, string specialty)
{
	this->name = move(name);
	this->age = age;
	this->dr_id = dr_id;
	this->specialty = move(specialty);
}

void doctor::details() const
{
	cout << "Name: " << name << "\tAge: " << age << "\tID: " << dr_id << "\tSpecialty: " << specialty << endl;
}
