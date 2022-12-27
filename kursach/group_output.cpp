#include <iostream>
#include <iomanip>
#include <fstream>

#include "constants.h"
#include "structures_definition.h"

using namespace std;




// ���������� �������:




// ����� ������ �� �������� � ������� (�������� ����������� ������):
void output_bus_to_console(bus_from_linear_singly_linked_list* bus);

// ����� ������ �� �������� � ������� (�������� ����������� ������):
void output_bus_to_console(bus_from_linear_doubly_linked_list* bus);

// ����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������):
void output_bus_to_file(bus_from_linear_singly_linked_list* bus);

// ����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������):
void output_bus_to_file(bus_from_linear_doubly_linked_list* bus);

// ����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������):
void save_bus_to_storage_file(bus_from_linear_singly_linked_list* bus);

// ����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������):
void save_bus_to_storage_file(bus_from_linear_doubly_linked_list* bus);

// ���������� ���� ��������� � ���� �������� �� (�������� ����������� ������):
void save_all_buses_to_storage_file(buses_linear_singly_linked_list* buses);

// ���������� ���� ��������� � ���� �������� �� (�������� ����������� ������):
void save_all_buses_to_storage_file(buses_linear_doubly_linked_list* buses);




// ����������� �������:




// ����� ������ �� �������� � ������� (�������� ����������� ������):
void output_bus_to_console(bus_from_linear_singly_linked_list* bus) {


	// ��������������� ������� � ������� ��� ������ � ������ ��������:

	cout << setw(15) << bus->bus_data->bus_destination;
	cout << setw(15) << bus->bus_data->bus_passage_number;
	cout << setw(18) << bus->bus_data->bus_brand;
	cout << setw(20) << bus->bus_data->bus_departure_time;
	cout << setw(35) << bus->bus_data->bus_full_name_of_the_driver;
	cout << setw(38) << bus->bus_data->bus_number_of_tickets_sold;
	cout << setw(15) << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // ����� ����� "����� ������ �� �������� � ������� (�������� ����������� ������)"




// ����� ������ �� �������� � ������� (�������� ����������� ������):
void output_bus_to_console(bus_from_linear_doubly_linked_list* bus) {


	// ��������������� ������� � ������� ��� ������ � ������ ��������:

	cout << setw(15) << bus->bus_data->bus_destination;
	cout << setw(15) << bus->bus_data->bus_passage_number;
	cout << setw(18) << bus->bus_data->bus_brand;
	cout << setw(20) << bus->bus_data->bus_departure_time;
	cout << setw(35) << bus->bus_data->bus_full_name_of_the_driver;
	cout << setw(38) << bus->bus_data->bus_number_of_tickets_sold;
	cout << setw(15) << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // ����� ����� "����� ������ �� �������� � ������� (�������� ����������� ������)




// ����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������):
void output_bus_to_file(bus_from_linear_singly_linked_list* bus){


	// ���������� ����������:

	ofstream output_file; // ����� ������ ������ � ����


	// �������� ����� �������� ������ � ������ ������ � ����� ����� (append):
	output_file.open(gl_output_file, std::ofstream::app);


	// ��������������� ������� � ������� ��� ������ � ������ ��������:

	output_file << bus->bus_data->bus_destination << " ";
	output_file << bus->bus_data->bus_passage_number << " ";
	output_file << bus->bus_data->bus_brand << " ";
	output_file << bus->bus_data->bus_departure_time << " ";
	output_file << bus->bus_data->bus_full_name_of_the_driver << " ";
	output_file << bus->bus_data->bus_number_of_tickets_sold << " ";
	output_file << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // ����� ����� "����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������)"




// ����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������):
void output_bus_to_file(bus_from_linear_doubly_linked_list* bus) {


	// ���������� ����������:

	ofstream output_file; // ����� ������ ������ � ����


	// �������� ����� �������� ������ � ������ ������ � ����� ����� (append):
	output_file.open(gl_output_file, std::ofstream::app);


	// ��������������� ������� � ������� ��� ������ � ������ ��������:

	output_file << bus->bus_data->bus_destination << " ";
	output_file << bus->bus_data->bus_passage_number << " ";
	output_file << bus->bus_data->bus_brand << " ";
	output_file << bus->bus_data->bus_departure_time << " ";
	output_file << bus->bus_data->bus_full_name_of_the_driver << " ";
	output_file << bus->bus_data->bus_number_of_tickets_sold << " ";
	output_file << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // ����� ����� "����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������)"




// ����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������):
void save_bus_to_storage_file(bus_from_linear_singly_linked_list* bus) {


	// ���������� ����������:

	ofstream storage_file; // ����� ������ ������ � ����


	// �������� ����� �������� ������ � ������ ������ � ����� ����� (append):
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app); 


	// ��������������� ������� � ������� ��� ������ � ������ ��������:

	storage_file << bus->bus_data->bus_destination << " ";
	storage_file << bus->bus_data->bus_passage_number << " ";
	storage_file << bus->bus_data->bus_brand << " ";
	storage_file << bus->bus_data->bus_departure_time << " ";
	storage_file << bus->bus_data->bus_full_name_of_the_driver << " ";
	storage_file << bus->bus_data->bus_number_of_tickets_sold << " ";
	storage_file << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // ����� ����� "����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������)"




// ����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������):
void save_bus_to_storage_file(bus_from_linear_doubly_linked_list* bus) {


	// ���������� ����������:

	ofstream storage_file; // ����� ������ ������ � ����


	// �������� ����� �������� ������ � ������ ������ � ����� ����� (append):
	storage_file.open(gl_bus_station_storage_file, std::ofstream::app);


	// ��������������� ������� � ������� ��� ������ � ������ ��������:

	storage_file << bus->bus_data->bus_destination << " ";
	storage_file << bus->bus_data->bus_passage_number << " ";
	storage_file << bus->bus_data->bus_brand << " ";
	storage_file << bus->bus_data->bus_departure_time << " ";
	storage_file << bus->bus_data->bus_full_name_of_the_driver << " ";
	storage_file << bus->bus_data->bus_number_of_tickets_sold << " ";
	storage_file << bus->bus_data->bus_estimated_number_of_passengers << endl;


} // ����� ����� "����� ������ �� �������� � ���� �������� ������ (�������� ����������� ������)"




// ���������� ���� ��������� � ���� �������� �� (�������� ����������� ������):
void save_all_buses_to_storage_file(buses_linear_singly_linked_list* buses){


	// ������� ���� �������� ��:
	ofstream file;
	file.open(gl_bus_station_storage_file);
	file.close();


	// �������� �������-�������� � ��������� ��� � ������ ������:
	bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;


	// ��������� ��� �������� ������ � �������� �� � ���� �������� ��:
	while (iterator_bus != NULL) {
		save_bus_to_storage_file(iterator_bus);
		iterator_bus = iterator_bus->bus_next_bus;
	}


} // ����� ����� "���������� ���� ��������� � ���� �������� �� (�������� ����������� ������)"




// ���������� ���� ��������� � ���� �������� �� (�������� ����������� ������):
void save_all_buses_to_storage_file(buses_linear_doubly_linked_list* buses) {


	// ������� ���� �������� ��:
	ofstream file;
	file.open(gl_bus_station_storage_file);
	file.close();


	// �������� �������-�������� � ��������� ��� � ������ ������:
	bus_from_linear_doubly_linked_list* iterator_bus = buses->buses_first_bus;


	// ��������� ��� �������� ������ � �������� �� � ���� �������� ��:
	while (iterator_bus != NULL) {
		save_bus_to_storage_file(iterator_bus);
		iterator_bus = iterator_bus->bus_next_bus;
	}


} // ����� ����� "���������� ���� ��������� � ���� �������� �� (�������� ����������� ������)"
