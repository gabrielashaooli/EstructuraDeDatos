#pragma once
#include "add_patient.h"
#include "list.h"
#include "load_doctors.h"
#include "doctor_queues.h"
#include "list_4_patients.h"
#include "search_delete_queues.h"


enum main_menu
{
	EXIT = 0,
	Add_Patient,
	see_doctors,
	see_doctor_queues,
	discharge_patient,
	see_all_patients,
	see_urgent,
};

inline void main_menu()
{
	queue queue_john, queue_mary, queue_peter;
	list doctors;
	list_4_patients complete_patients;
	load_doctors(doctors);
	patient new_patient;
	int choice;
	do
	{
		cout << endl << endl << "MAIN MENU" << endl;
		cout << "1. Add patient" << endl;
		cout << "2. See doctors" << endl;
		cout << "3. See doctor's queue" << endl;
		cout << "4. Discharge Patient by ID" << endl;
		cout << "5. See All Patients" << endl;
		cout << "6. See Urgent Patients" << endl;
		cout << "0) EXIT" << endl;

		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case Add_Patient:
			new_patient = add_patient();
			if (new_patient.doctor_2_visit == 1) queue_john.enqueue(new_patient);
			else if (new_patient.doctor_2_visit == 2) queue_mary.enqueue(new_patient);
			else if (new_patient.doctor_2_visit == 3) queue_peter.enqueue(new_patient);
			else
			{
				cout << "Invalid doctor ID" << endl;
				new_patient = add_patient();
			}
			complete_patients.insert(new_patient);
			break;

		case see_doctors:
			doctors.show_full();
			break;

		case see_doctor_queues:
			doctor_queues(queue_john, queue_mary, queue_peter);
			break;

		case discharge_patient:
			int id;
			cout << "Enter ID: ";
			cin >> id;
			complete_patients.delete_id(id);
			search_delete_queues(queue_john, queue_mary, queue_peter, id);
			break;

		case see_all_patients:
			complete_patients.show_full();
			break;

		case see_urgent:
			complete_patients.show_urgent();
			break;

		case EXIT:
			cout << "EXITING PROGRAM" << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 0);
}