

#include "structures_definition.h"
#include "additional_functions.h"
#include <iostream>
#include "group_sort.h"

using namespace std;


// ���������� �� ��������� �������:
void console_menu_option_sort_data(bus_station* bs) {

	cout << "\t����������\n\n";


	if (bs->bus_station_type_of_list == '1') {

		if (bs->bus_station_buses_linear_singly_linked_list->buses_first_bus == NULL) return; // ������ ����

		if (bs->bus_station_buses_linear_singly_linked_list->buses_first_bus->bus_next_bus == NULL) return; // � ������ 1 �������

	}
	else {

		if (bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus == NULL) return; // ������ ����

		if (bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus->bus_next_bus == NULL) return; // � ������ 1 �������

	}

	string user_input; // ���������������� ����

	int n = 7; // ����� ���������� ������

	int choosen_option; // ��������� �������� 

	string sort_mode; // ���������� �� �������� ��� �����������

	cout << "- �� ����� �������� ����������� ������?\n";

	cout << "����������� (1)"
		<< " / " << "����� ����� (2)"
		<< " / " << "����� �������� (3)"
		<< " / " << "����� ����������� (4)"
		<< " / " << "��� �������� (5)"
		<< " / " << "����� ��������� ������� (6)"
		<< " / " << "��������� ����� ���������� (7)\n\n";


	user_input = get_user_input_with_conditions(n + 1, "lower_then_n");

	choosen_option = stoi(user_input);

	cout << "\n- ���������� �� ����������� (1) ��� �������� (2)?\n\n";

	sort_mode = get_user_input_with_conditions(0, "is_1_or_2");

	sort(sort_mode, choosen_option, bs);


}