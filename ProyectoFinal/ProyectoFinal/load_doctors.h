#pragma once
inline void load_doctors(list & doctors)
{
	const auto doctor1 = doctor("John", 30, 1, "Cardiology");
	const auto doctor2 = doctor("Mary", 40, 2, "Neurology");
	const auto doctor3 = doctor("Peter", 50, 3, "Dermatology");
	doctors.insert(doctor1);
	doctors.insert(doctor2);
	doctors.insert(doctor3);
	cout << "DOCTORS LOADED" << endl;
}