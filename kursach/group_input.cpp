// ����������� ����������� ���������:
#include <fstream>
#include <iostream>
#include <iomanip>




// ����������� ������������ ����������� ����: 
using namespace std;




// ����������� ������ ������ ���������:
#include "structures_definition.h"
#include "additional_functions.h"
#include "constants.h"




// ���������� �������, ������� ����� � ���� ����� ����� ����������:

// ���� ���� ������ �� ����� (�������� ����������� ������)
void input_all_data_from_file(buses_linear_singly_linked_list* buses); 

// ���� ���� ������ �� ����� (�������� ����������� ������)
void input_all_data_from_file(buses_linear_doubly_linked_list* buses);

// ���� ���� ������ �� ������� (�������� ����������� ������):
void input_all_data_from_console(buses_linear_singly_linked_list* buses);

// ���� ���� ������ �� ������� (�������� ����������� ������):
void input_all_data_from_console(buses_linear_doubly_linked_list* buses);

// �������� ������ �� ����� (�������� ����������� ������):
void add_data_from_file(buses_linear_singly_linked_list* buses);

// �������� ������ �� ����� (�������� ����������� ������):
void add_data_from_file(buses_linear_doubly_linked_list* buses);

// �������� ������ �� ������� (�������� ����������� ������):
void add_data_from_console(buses_linear_singly_linked_list* buses);

// �������� ������ �� ������� (�������� ����������� ������):
void add_data_from_console(buses_linear_doubly_linked_list* buses);



// ���� ���� ������ �� ����� (�������� ����������� ������):
void input_all_data_from_file(buses_linear_singly_linked_list* buses) {


	// ��������� ���� ������� ������ � ������ ������:
	ifstream intput_file;
	intput_file.open(gl_input_file);


	// ��������� ���� ��� �������� �� � ������ ������:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file);


	// ��������� ������ ������� �� �����:
	if (!intput_file.eof()) {


		// ������� ������ � ������ �������� � ������:
		buses->buses_first_bus = new bus_from_linear_singly_linked_list;


		// �������� ������ ��� ������ � ������ ��������:
		buses->buses_first_bus->bus_data = new bus_data;


		// ���� ��� ������� �������� ���:
		buses->buses_first_bus->bus_next_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		intput_file >> buses->buses_first_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_destination << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_passage_number << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << buses->buses_first_bus->bus_data->bus_brand << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		intput_file >> f >> i >> o; // ��������� ��������������� ��� ������
		buses->buses_first_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << buses->buses_first_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers << "\n";


	} // ����� ����� "��������� ������ ������� �� �����"


	// ��� "��������" �� ������ ������� ����������-�������:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;


	// ������ ��������� ��� ���������� ��������:
	while (!intput_file.eof()) {


		// ������� ������ � ��������� ��������:
		iterator_bus->bus_next_bus = new bus_from_linear_singly_linked_list;


		// ��������� � ���������� ��������::
		iterator_bus = iterator_bus->bus_next_bus;


		// �������� ������ ��� ������ � ������ ��������:
		iterator_bus->bus_data = new bus_data;


		// ���� ��� ���������� �������� ���:
		iterator_bus->bus_next_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		intput_file >> iterator_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		intput_file >> iterator_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		intput_file >> iterator_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		intput_file >> iterator_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		intput_file >> f >> i >> o; // ��������� ��������������� ��� ������
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> iterator_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

	} // ����� ����� "������ ��������� ��� ���������� ��������"



	// ��������� �����:
	intput_file.close();
	storage_file.close();


} // ����� ����� "���� ���� ������ �� ����� (�������� ����������� ������)"




// ���� ���� ������ �� ����� (�������� ����������� ������):
void input_all_data_from_file(buses_linear_doubly_linked_list* buses) {


	// ��������� ���� ������� ������ � ������ ������:
	ifstream intput_file;
	intput_file.open(gl_input_file);


	// ��������� ���� ��� �������� �� � ������ ������:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file);


	// ��������� ������ ������� �� �����:
	if (!intput_file.eof()) {


		// ������� ������ � ������ �������� � ������:
		buses->buses_first_bus = new bus_from_linear_doubly_linked_list;


		// �������� ������ ��� ������ � ������ ��������:
		buses->buses_first_bus->bus_data = new bus_data;
		buses->buses_first_bus->bus_next_bus = NULL;
		buses->buses_first_bus->bus_previous_bus = NULL;


		// ���� ��� ��������� ������� - ��� � ������ �������
		buses->buses_last_bus = buses->buses_first_bus;
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		intput_file >> buses->buses_first_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_destination << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_passage_number << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << buses->buses_first_bus->bus_data->bus_brand << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		intput_file >> f >> i >> o; // ��������� ��������������� ��� ������
		buses->buses_first_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << buses->buses_first_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers << "\n";


	} // ����� ����� "��������� ������ ������� �� �����"


	// ������ ��������� ��� ���������� ��������:
	while (!intput_file.eof()) {


		// � �������������� ���������� �������� ����� ���������� ��������:
		bus_from_linear_doubly_linked_list* tmp;
		tmp = buses->buses_last_bus;


		// ������� ������ � ��������� �������� � ������ ��� ������ ������:
		buses->buses_last_bus->bus_next_bus = new bus_from_linear_doubly_linked_list;
		buses->buses_last_bus = buses->buses_last_bus->bus_next_bus;


		// �������� ������ ��� ������ � ��������� ��������:
		buses->buses_last_bus->bus_data = new bus_data;


		// ���� ��� ���������� �������� ���, � ���������� ������� - ��� ���������� ����� ������:
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = tmp;


		// ��������������� ��������� ������ � ������ ��������:

		intput_file >> buses->buses_last_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_destination << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_passage_number << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << buses->buses_last_bus->bus_data->bus_brand << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		intput_file >> f >> i >> o; // ��������� ��������������� ��� ������
		buses->buses_last_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << buses->buses_last_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers << "\n";

	} // ����� ����� "������ ��������� ��� ���������� ��������"



	// ��������� �����:
	intput_file.close();
	storage_file.close();


} // ����� ����� "���� ���� ������ �� ����� (�������� ����������� ������)"




// ���� ���� ������ �� ������� (�������� ����������� ������):
void input_all_data_from_console(buses_linear_singly_linked_list* buses) {


	string user_input; // ���������������� ����

	int n; // ����� �������� ���������

	// ��������� ���� ��� �������� �� � ������ ������:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file);


	cout << "������� ���������� ���������, ������ � ������� �� ������ ������. ";


	// ���������� ������ ������������:
	user_input = get_user_input_with_conditions(0, "natural_number");


	cout << "������� ��� ������� ��������:\n";
	cout << setiosflags(ios::left);
	cout << setw(15) << "�����������"
		<< setw(15) << "����� �����"
		<< setw(18) << "����� ��������"
		<< setw(20) << "����� �����������"
		<< setw(35) << "��� ��������"
		<< setw(38) << "����� ��������� ������� (�� ������)"
		<< setw(15) << "��������� ����� ���������� (�� �������)\n";

	n = stoi(user_input);

	if (n > 0) {

		buses->buses_first_bus = new bus_from_linear_singly_linked_list;
		buses->buses_first_bus->bus_data = new bus_data;
		buses->buses_first_bus->bus_next_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		cin >> buses->buses_first_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_destination << " ";

		cin >> buses->buses_first_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_passage_number << " ";

		cin >> buses->buses_first_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << buses->buses_first_bus->bus_data->bus_brand << " ";

		cin >> buses->buses_first_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		cin >> f >> i >> o; // ��������� ��������������� ��� ������
		buses->buses_first_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> buses->buses_first_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << buses->buses_first_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers << "\n";


		n--;
	}


	// ��� "��������" �� ������ ������� ����������-�������:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;

	while (n > 0) {


		// ������� ������ � ��������� ��������:
		iterator_bus->bus_next_bus = new bus_from_linear_singly_linked_list;


		// ��������� � ���������� ��������::
		iterator_bus = iterator_bus->bus_next_bus;


		// �������� ������ ��� ������ � ������ ��������:
		iterator_bus->bus_data = new bus_data;


		// ���� ��� ���������� �������� ���:
		iterator_bus->bus_next_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		cin >> iterator_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		cin >> iterator_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		cin >> iterator_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		cin >> iterator_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		cin >> f >> i >> o; // ��������� ��������������� ��� ������
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> iterator_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

		n--;
	}


	// ��������� �����:
	storage_file.close();


} // ����� ����� "���� ���� ������ �� ������� (�������� ����������� ������)"




// ���� ���� ������ �� ������� (�������� ����������� ������):
void input_all_data_from_console(buses_linear_doubly_linked_list* buses) {


	string user_input; // ���������������� ����

	int n; // ����� �������� ���������

	// ��������� ���� ��� �������� �� � ������ ������:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file);


	cout << "������� ���������� ���������, ������ � ������� �� ������ ������: ";


	// ���������� ������ ������������:
	user_input = get_user_input_with_conditions(0, "natural_number");


	cout << "������� ��� ������� ��������:";
	cout << setiosflags(ios::left);
	cout << setw(15) << "�����������"
		<< setw(15) << "����� �����"
		<< setw(18) << "����� ��������"
		<< setw(20) << "����� �����������"
		<< setw(35) << "��� ��������"
		<< setw(38) << "����� ��������� ������� (�� ������)"
		<< setw(15) << "��������� ����� ���������� (�� �������)\n";

	n = stoi(user_input);

	if (n > 0) {


		// ������� ������ � ������ �������� � ������:
		buses->buses_first_bus = new bus_from_linear_doubly_linked_list;


		// �������� ������ ��� ������ � ������ ��������:
		buses->buses_first_bus->bus_data = new bus_data;
		buses->buses_first_bus->bus_next_bus = NULL;
		buses->buses_first_bus->bus_previous_bus = NULL;


		// ���� ��� ��������� ������� - ��� � ������ �������
		buses->buses_last_bus = buses->buses_first_bus;
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		cin >> buses->buses_first_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_destination << " ";

		cin >> buses->buses_first_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_passage_number << " ";

		cin >> buses->buses_first_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << buses->buses_first_bus->bus_data->bus_brand << " ";

		cin >> buses->buses_first_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		cin >> f >> i >> o; // ��������� ��������������� ��� ������
		buses->buses_first_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << buses->buses_first_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> buses->buses_first_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << buses->buses_first_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << buses->buses_first_bus->bus_data->bus_estimated_number_of_passengers << "\n";


		n--;
	}


	// ������ ��������� ��� ���������� ��������:
	while (n > 0) {


		// � �������������� ���������� �������� ����� ���������� ��������:
		bus_from_linear_doubly_linked_list* tmp;
		tmp = buses->buses_last_bus;


		// ������� ������ � ��������� �������� � ������ ��� ������ ������:
		buses->buses_last_bus->bus_next_bus = new bus_from_linear_doubly_linked_list;
		buses->buses_last_bus = buses->buses_last_bus->bus_next_bus;


		// �������� ������ ��� ������ � ��������� ��������:
		buses->buses_last_bus->bus_data = new bus_data;


		// ���� ��� ���������� �������� ���, � ���������� ������� - ��� ���������� ����� ������:
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = tmp;


		// ��������������� ��������� ������ � ������ ��������:

		cin >> buses->buses_last_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_destination << " ";

		cin >> buses->buses_last_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_passage_number << " ";

		cin >> buses->buses_last_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << buses->buses_last_bus->bus_data->bus_brand << " ";

		cin >> buses->buses_last_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		cin >> f >> i >> o; // ��������� ��������������� ��� ������
		buses->buses_last_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> buses->buses_last_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << buses->buses_last_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers << "\n";

		n--;

	} // ����� ����� "������ ��������� ��� ���������� ��������"


	// ��������� �����:
	storage_file.close();


} // ����� ����� "���� ���� ������ �� ������� (�������� ����������� ������)"




// �������� ������ �� ����� (�������� ����������� ������):
void add_data_from_file(buses_linear_singly_linked_list* buses) {

	// ��������� ���� ������� ������ � ������ ������:
	ifstream intput_file;
	intput_file.open(gl_input_file);


	// ��������� ���� ��� �������� �� � ������ ������:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	// ��� "��������" �� ������ ������� ����������-�������:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;


	// ������ �� ����� ������:
	while (iterator_bus->bus_next_bus != NULL) {

		iterator_bus = iterator_bus->bus_next_bus;

	}


	// ������ ��������� ��� ��������:
	while (!intput_file.eof()) {


		// ������� ������ � ��������� ��������:
		iterator_bus->bus_next_bus = new bus_from_linear_singly_linked_list;


		// ��������� � ���������� ��������::
		iterator_bus = iterator_bus->bus_next_bus;


		// �������� ������ ��� ������ � ������ ��������:
		iterator_bus->bus_data = new bus_data;


		// ���� ��� ���������� �������� ���:
		iterator_bus->bus_next_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		intput_file >> iterator_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		intput_file >> iterator_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		intput_file >> iterator_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		intput_file >> iterator_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		intput_file >> f >> i >> o; // ��������� ��������������� ��� ������
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> iterator_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

	} // ����� ����� "������ ��������� ��� ���������� ��������"



	// ��������� �����:
	intput_file.close();
	storage_file.close();

}





// �������� ������ �� ����� (�������� ����������� ������):
void add_data_from_file(buses_linear_doubly_linked_list* buses) {

	// ��������� ���� ������� ������ � ������ ������:
	ifstream intput_file;
	intput_file.open(gl_input_file);


	// ��������� ���� ��� �������� �� � ������ ������:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	// ��� "��������" �� ������ ������� ����������-�������:
	bus_from_linear_doubly_linked_list* iterator_bus = buses->buses_last_bus;


	// ������ ��������� ��� ��������:
	while (!intput_file.eof()) {


		// ������� ������ � ��������� ��������:
		iterator_bus->bus_next_bus = new bus_from_linear_doubly_linked_list;


		// ��������� � ���������� ��������::
		iterator_bus = iterator_bus->bus_next_bus;


		// �������� ������ ��� ������ � ������ ��������:
		iterator_bus->bus_data = new bus_data;


		// ���� ��� ���������� �������� ���:
		iterator_bus->bus_next_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		intput_file >> iterator_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		intput_file >> iterator_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		intput_file >> iterator_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		intput_file >> iterator_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		intput_file >> f >> i >> o; // ��������� ��������������� ��� ������
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		intput_file >> iterator_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		intput_file >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

	} // ����� ����� "������ ��������� ��� ���������� ��������"

	buses->buses_last_bus = iterator_bus;

	// ��������� �����:
	intput_file.close();
	storage_file.close();

}




// �������� ������ �� ������� (�������� ����������� ������):
void add_data_from_console(buses_linear_singly_linked_list* buses) {


	string user_input; // ���������������� ����

	int n; // ����� �������� ���������

	// ��������� ���� ��� �������� �� � ������ ������:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	cout << "������� ���������� ���������, ������ � ������� �� ������ ������. ";


	// ���������� ������ ������������:
	user_input = get_user_input_with_conditions(0, "natural_number");


	cout << "������� ��� ������� ��������:\n";
	cout << setiosflags(ios::left);
	cout << setw(15) << "�����������"
		<< setw(15) << "����� �����"
		<< setw(18) << "����� ��������"
		<< setw(20) << "����� �����������"
		<< setw(35) << "��� ��������"
		<< setw(38) << "����� ��������� ������� (�� ������)"
		<< setw(15) << "��������� ����� ���������� (�� �������)\n";


	n = stoi(user_input);


	// ��� "��������" �� ������ ������� ����������-�������:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;


	// ������ �� ����� ������:
	while (iterator_bus->bus_next_bus != NULL) {

		iterator_bus = iterator_bus->bus_next_bus;

	}


	while (n > 0) {


		// ������� ������ � ��������� ��������:
		iterator_bus->bus_next_bus = new bus_from_linear_singly_linked_list;


		// ��������� � ���������� ��������::
		iterator_bus = iterator_bus->bus_next_bus;


		// �������� ������ ��� ������ � ������ ��������:
		iterator_bus->bus_data = new bus_data;


		// ���� ��� ���������� �������� ���:
		iterator_bus->bus_next_bus = NULL;


		// ��������������� ��������� ������ � ������ ��������:

		cin >> iterator_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_destination << " ";

		cin >> iterator_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << iterator_bus->bus_data->bus_passage_number << " ";

		cin >> iterator_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << iterator_bus->bus_data->bus_brand << " ";

		cin >> iterator_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		cin >> f >> i >> o; // ��������� ��������������� ��� ������
		iterator_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << iterator_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> iterator_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << iterator_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> iterator_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << iterator_bus->bus_data->bus_estimated_number_of_passengers << "\n";

		n--;
	}


	// ��������� �����:
	storage_file.close();



}




// �������� ������ �� ������� (�������� ����������� ������):
void add_data_from_console(buses_linear_doubly_linked_list* buses) {



	string user_input; // ���������������� ����

	int n; // ����� �������� ���������

	// ��������� ���� ��� �������� �� � ������ ������:
	ofstream storage_file;
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	cout << "������� ���������� ���������, ������ � ������� �� ������ ������: ";


	// ���������� ������ ������������:
	user_input = get_user_input_with_conditions(0, "natural_number");


	cout << "������� ��� ������� ��������:";
	cout << setiosflags(ios::left);
	cout << setw(15) << "�����������"
		<< setw(15) << "����� �����"
		<< setw(18) << "����� ��������"
		<< setw(20) << "����� �����������"
		<< setw(35) << "��� ��������"
		<< setw(38) << "����� ��������� ������� (�� ������)"
		<< setw(15) << "��������� ����� ���������� (�� �������)\n";

	n = stoi(user_input);



	// ������ ��������� ��� ���������� ��������:
	while (n > 0) {


		// � �������������� ���������� �������� ����� ���������� ��������:
		bus_from_linear_doubly_linked_list* tmp = buses->buses_last_bus;


		// ������� ������ � ��������� �������� � ������ ��� ������ ������:
		buses->buses_last_bus->bus_next_bus = new bus_from_linear_doubly_linked_list;
		buses->buses_last_bus = buses->buses_last_bus->bus_next_bus;


		// �������� ������ ��� ������ � ��������� ��������:
		buses->buses_last_bus->bus_data = new bus_data;


		// ���� ��� ���������� �������� ���, � ���������� ������� - ��� ���������� ����� ������:
		buses->buses_last_bus->bus_next_bus = NULL;
		buses->buses_last_bus->bus_previous_bus = tmp;


		// ��������������� ��������� ������ � ������ ��������:

		cin >> buses->buses_last_bus->bus_data->bus_destination; // ����� ���������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_destination << " ";

		cin >> buses->buses_last_bus->bus_data->bus_passage_number; // ����� ����� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_passage_number << " ";

		cin >> buses->buses_last_bus->bus_data->bus_brand; // ����� ������� �������� 
		storage_file << buses->buses_last_bus->bus_data->bus_brand << " ";

		cin >> buses->buses_last_bus->bus_data->bus_departure_time; // ����� ����������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_departure_time << " ";

		string f, i, o; // ��� ������ � ���� �������, ��� �������� ���������� ����������
		cin >> f >> i >> o; // ��������� ��������������� ��� ������
		buses->buses_last_bus->bus_data->bus_full_name_of_the_driver = f + " " + i + " " + o; // ��� �������� ������� ��������
		storage_file << buses->buses_last_bus->bus_data->bus_full_name_of_the_driver << " ";

		cin >> buses->buses_last_bus->bus_data->bus_number_of_tickets_sold; // ����� ��������� � ������ �������� ������� �� ��������� ������
		storage_file << buses->buses_last_bus->bus_data->bus_number_of_tickets_sold << " ";

		cin >> buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers; // ��������� ���������� ����������, ������� ������ �� ������ �������� �������
		storage_file << buses->buses_last_bus->bus_data->bus_estimated_number_of_passengers << "\n";

		n--;

	} // ����� ����� "������ ��������� ��� ���������� ��������"


	// ��������� �����:
	storage_file.close();

}