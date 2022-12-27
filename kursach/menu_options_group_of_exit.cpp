#include <iostream>
#include "structures_definition.h"
#include "additional_functions.h"
#include "group_delete.h"

using namespace std;


// �������� ���������:
void console_menu_option_exit_programm(bus_station* bs) {


	cout << "\t����� �� ���������\n\n";


	// ���������� ����������:
	string user_input; // ���������������� ����


	cout << "- �� ����� �������� (1 - ����� �� ���������, 2 - ��������� � ����)?\n";

		
	user_input = get_user_input_with_conditions(0, "is_1_or_2");

	// ����������� � ���� �� ������� ������������:
	if (user_input == "2") {
		
		
		// �������� � ����
		return;


	} // ����� ����� "����������� � ���� �� ������� ������������"


	// � ������ ����������� �������
	if (bs->bus_station_type_of_list == '1') {


		// ������ ����������� ������ ��������� � ������ � ��� � ����� �������� ��:
		delete_all_data(bs->bus_station_buses_linear_singly_linked_list);


	}
	else { // � ������ ����������� �������


		/// ������ ����������� ������ ��������� � ������ � ��� � ����� �������� ��:
		delete_all_data(bs->bus_station_buses_linear_doubly_linked_list);


	}

		

	// ������ �� ���������:
	exit(0);


} // ����� ����� "�������� ���������"