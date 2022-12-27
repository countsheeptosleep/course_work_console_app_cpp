#include "constants.h"
#include "structures_definition.h"
#include "additional_functions.h"
#include "group_output.h"
#include <iostream>
#include <iomanip> 
#include <fstream>

using namespace std;



// ����� ���� ������ �� �����:
void console_menu_option_output_all_data_to_console(bus_station* bs) {

	cout << "\t����� ���� ������ � �������\n\n";

	if (bs->bus_station_type_of_list == '1') { // �����������

		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;

		if (iterator_bus == NULL) {

			
			cout << "��������� �� ������� ���...\n\n";

			return;

		}

		int i = 1;
		cout << setiosflags(ios::left);
		cout << setw(5) << "�"
			<< setw(15) << "�����������" 
			<< setw(15) << "����� �����"
			<< setw(18) << "����� ��������"
			<< setw(20) << "����� �����������"
			<< setw(35) << "��� ��������"
			<< setw(38) << "����� ��������� ������� (�� ������)"
			<< setw(15) << "��������� ����� ���������� (�� �������)\n";

		while (iterator_bus != NULL) { // ���������� �������� ��������

			cout << setw(5) << i;
			output_bus_to_console(iterator_bus);

			iterator_bus = iterator_bus->bus_next_bus;
			i++;
		}

	}


	else { // �����������

		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;

		if (iterator_bus == NULL) {


			cout << "��������� �� ������� ���...\n\n";

			return;

		}

		int i = 1;
		cout << setiosflags(ios::left);
		cout << setw(5) << "�"
			<< setw(15) << "�����������"
			<< setw(15) << "����� �����"
			<< setw(18) << "����� ��������"
			<< setw(20) << "����� �����������"
			<< setw(35) << "��� ��������"
			<< setw(38) << "����� ��������� ������� (�� ������)"
			<< setw(15) << "��������� ����� ���������� (�� �������)\n";

		while (iterator_bus != NULL) { // ���������� �������� ��������

			cout << setw(5) << i;
			output_bus_to_console(iterator_bus);

			iterator_bus = iterator_bus->bus_next_bus;
			i++;
		}

	}

	
}

// ����� ���� ������ � ����:
void console_menu_option_output_all_data_to_file(bus_station* bs) {


	cout << "\t����� ���� ������ � ����\n\n";


	// ���� �������� ������ � ������ ������:
	ofstream output_file;

	// ������� ������� �����:
	output_file.open(gl_output_file, std::ofstream::out | std::ofstream::trunc); 
	output_file.close();


	if (bs->bus_station_type_of_list == '1') {

		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;

		if (iterator_bus == NULL) {


			cout << "��������� �� ������� ���...\n\n";

			return;

		}


		while (iterator_bus != NULL) { // ���������� �������� ��������

			output_bus_to_file(iterator_bus);
				
			iterator_bus = iterator_bus->bus_next_bus;

		}

	}


	else {

		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;

		if (iterator_bus == NULL) {


			cout << "��������� �� ������� ���...\n\n";

			return;

		}


		while (iterator_bus != NULL) { // ���������� �������� ��������

			output_bus_to_file(iterator_bus);

			iterator_bus = iterator_bus->bus_next_bus;
		}

	}


}


// ����� �� ����� ������ �� ��������� �������:
void console_menu_option_output_choosen_data_to_console(bus_station* bs) {


	cout << "\t����� � ������� ������ �� ��������� �������\n\n";

	string user_input; // ���������������� ����

	int n = 7; // ����� ���������� ������

	int choosen_option; // ��������� �������� ������

	cout << "- �� ����� �������� �������� ������?\n";

	cout << "����������� (1)"
		<< " / " << "����� ����� (2)"
		<< " / " << "����� �������� (3)"
		<< " / " << "����� ����������� (4)"
		<< " / " << "��� �������� (5)"
		<< " / " << "����� ��������� ������� (6)"
		<< " / " << "��������� ����� ���������� (7)\n\n";


	user_input = get_user_input_with_conditions(n+1, "lower_then_n");

	choosen_option = stoi(user_input);

	switch (choosen_option) { // �������� ����� ��� ������ �� ���

	case 1:
		cout << "������� �����������. ";
		cin >> user_input;
		break;
	case 2:
		cout << "������� ����� �����. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;
	case 3:
		cout << "������� ����� ��������: ";
		cin >> user_input;
		break;
	case 4:
		cout << "������� ����� �����������: ";
		cin >> user_input;
		break;
	case 5:
		cout << "������� ��� ��������: ";
		cin.ignore();
		getline(cin, user_input);
		break;
	case 6:
		cout << "������� ����� ��������� �������. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;
	case 7:
		cout << "������� ��������� ����� ����������. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;

	default:
		cout << "error";
		return;

	}

	cout << "\n���� ���������� ��������...\n\n";

	bool flag = false; // ��� �� ������ ���� ���� ���������� �������

	if (bs->bus_station_type_of_list == '1') {

		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;



		while (iterator_bus != NULL) { // ���������� ��������

			switch (choosen_option) { // � ����������� �� ����� ��������� ������� � ������

			case 1:
				if (user_input == iterator_bus->bus_data->bus_destination) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 2:
				if (stoi(user_input) == iterator_bus->bus_data->bus_passage_number) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 3:
				if (user_input == iterator_bus->bus_data->bus_brand) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 4:
				if (user_input == iterator_bus->bus_data->bus_departure_time) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 5:
				if (user_input == iterator_bus->bus_data->bus_full_name_of_the_driver) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 6:
				if (stoi(user_input) == iterator_bus->bus_data->bus_number_of_tickets_sold) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 7:
				if (stoi(user_input) == iterator_bus->bus_data->bus_estimated_number_of_passengers) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;

			default:
				cout << "error";
				return;

			}

			iterator_bus = iterator_bus->bus_next_bus;
		}

		

	}
	else {

		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;




		while (iterator_bus != NULL) { // ���������� ��� ��������

			switch (choosen_option) { // � ����������� �� ����� ��������� ������� � ������

			case 1:
				if (user_input == iterator_bus->bus_data->bus_destination) {
					output_bus_to_console(iterator_bus);
					flag = true;

				}
				break;
			case 2:
				if (stoi(user_input) == iterator_bus->bus_data->bus_passage_number) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 3:
				if (user_input == iterator_bus->bus_data->bus_brand) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 4:
				if (user_input == iterator_bus->bus_data->bus_departure_time) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 5:
				if (user_input == iterator_bus->bus_data->bus_full_name_of_the_driver) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 6:
				if (stoi(user_input) == iterator_bus->bus_data->bus_number_of_tickets_sold) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;
			case 7:
				if (stoi(user_input) == iterator_bus->bus_data->bus_estimated_number_of_passengers) {
					output_bus_to_console(iterator_bus);
					flag = true;
				}
				break;

			default:
				cout << "error";
				return;
			}

			iterator_bus = iterator_bus->bus_next_bus;
		}




	}
	if (!flag) {
		cout << "\n���������� ��������� ���...\n\n";
	}


} // ����� ����� "����� �� ����� ������ �� ��������� �������"

// ����� � ���� ������ �� ��������� �������:
void console_menu_option_output_choosen_data_to_file(bus_station* bs) {


	cout << "\t����� � ���� ������ �� ��������� �������\n\n";

	string user_input; // ���������������� ����

	int n = 7; // ����� ���������� ������

	int choosen_option; // ��������� �������� ������

	// ������ ����� ������� ��������:
	ofstream output_file;
	output_file.open(gl_output_file);
	output_file.close();

	cout << "- �� ����� �������� �������� ������?\n";

	cout << "����������� (1)"
		<< " / " << "����� ����� (2)"
		<< " / " << "����� �������� (3)"
		<< " / " << "����� ����������� (4)"
		<< " / " << "��� �������� (5)"
		<< " / " << "����� ��������� ������� (6)"
		<< " / " << "��������� ����� ���������� (7)\n\n";


	user_input = get_user_input_with_conditions(n + 1, "lower_then_n");

	choosen_option = stoi(user_input);

	switch (choosen_option) { // �������� �����

	case 1:
		cout << "������� �����������. ";
		cin >> user_input;
		break;
	case 2:
		cout << "������� ����� �����. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;
	case 3:
		cout << "������� ����� ��������: ";
		cin >> user_input;
		break;
	case 4:
		cout << "������� ����� �����������: ";
		cin >> user_input;
		break;
	case 5:
		cout << "������� ��� ��������: ";
		cin.ignore();
		getline(cin, user_input);
		break;
	case 6:
		cout << "������� ����� ��������� �������. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;
	case 7:
		cout << "������� ��������� ����� ����������. ";
		user_input = get_user_input_with_conditions(0, "natural_number");
		break;

	default:
		cout << "error";
		return;

	}

	cout << "\n���� ���������� ��������...\n\n";

	bool flag = false; // ��� �� ������ ���� ���� ���������� �������

	if (bs->bus_station_type_of_list == '1') {

		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;



		while (iterator_bus != NULL) {

			switch (choosen_option) {

			case 1:
				if (user_input == iterator_bus->bus_data->bus_destination) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 2:
				if (stoi(user_input) == iterator_bus->bus_data->bus_passage_number) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 3:
				if (user_input == iterator_bus->bus_data->bus_brand) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 4:
				if (user_input == iterator_bus->bus_data->bus_departure_time) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 5:
				if (user_input == iterator_bus->bus_data->bus_full_name_of_the_driver) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 6:
				if (stoi(user_input) == iterator_bus->bus_data->bus_number_of_tickets_sold) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 7:
				if (stoi(user_input) == iterator_bus->bus_data->bus_estimated_number_of_passengers) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;

			default:
				cout << "error";
				return;

			}

			iterator_bus = iterator_bus->bus_next_bus;
		}



	}
	else {

		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;




		while (iterator_bus != NULL) { // ���������� ��������

			switch (choosen_option) { // � ����������� �� ����� ��������� ������� � ������

			case 1:
				if (user_input == iterator_bus->bus_data->bus_destination) {
					output_bus_to_file(iterator_bus);
					flag = true;

				}
				break;
			case 2:
				if (stoi(user_input) == iterator_bus->bus_data->bus_passage_number) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 3:
				if (user_input == iterator_bus->bus_data->bus_brand) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 4:
				if (user_input == iterator_bus->bus_data->bus_departure_time) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 5:
				if (user_input == iterator_bus->bus_data->bus_full_name_of_the_driver) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 6:
				if (stoi(user_input) == iterator_bus->bus_data->bus_number_of_tickets_sold) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;
			case 7:
				if (stoi(user_input) == iterator_bus->bus_data->bus_estimated_number_of_passengers) {
					output_bus_to_file(iterator_bus);
					flag = true;
				}
				break;

			default:
				cout << "error";
				return;
			}

			iterator_bus = iterator_bus->bus_next_bus;
		}




	}
	if (!flag) {
		cout << "\n���������� ��������� ���...\n\n";

	}



}