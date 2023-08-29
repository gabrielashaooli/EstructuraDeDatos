#pragma once
#include <string>
#include <iostream>
using namespace std;

class patient
{
public:
	patient();
	patient(int, string, int, int, string, int);

	int id{};
	string name{};
	int age{};
	int doctor_2_visit{};
	string cause;
	int urgency{};

	int get_id() const;

	void details() const
	{
		cout << "PATIENT ID: " << id << "\t" << "NAME: " << name << "\t" << "AGE: " << age << "\t" <<
			"DOCTOR TO VISIT: " << doctor_2_visit << "\t" << "CAUSE: " << cause << "\t" << "URGENCY: " << urgency <<
			endl;
	}
};

