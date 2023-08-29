#pragma once
#include <string>
using namespace std;

class doctor
{
public:
	doctor();
	doctor(string, int, int, string);

	string name{};
	int age{};
	int dr_id{};
	string specialty{};

	void details() const;
};

