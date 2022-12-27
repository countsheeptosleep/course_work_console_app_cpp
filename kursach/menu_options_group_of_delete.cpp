// --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------
// ----------------------------------- �������� ������ ----------------------------------------
// --------------------------------------------------------------------------------------------
// -----------���� ����������� ������� ����� ���� �� ������ ����� �������� ������--------------
// --------------------------------------------------------------------------------------------




// ����������� ����������� ���������:
#include <iostream>
#include <fstream>




// ����������� ������������ ����������� ����:
using namespace std;




// ����������� ������ ������ ���������:
#include "structures_definition.h" // ���� � ������������ �������� �������� (��������, � ���������, 
								   // ����������� ��������� ���������� ������� bus_station, ��������� ������ ��������� � �.�.) 

#include "additional_functions.h" // ���� � ����������� �������������� ������� (����� ��� "�������� �� ������ ������ �� 1 �� n)

#include "group_delete.h" // ���� � ����������� �������, ���������� ������� ����� ��������� �������� ������

#include "group_output.h" // ���� � ����������� �������, ���������� ������� ����� ��������� ������ ������

#include "constants.h" // ���� � ������������ ��������




// ���������� �������:

// �������� ���� ������:
void console_menu_option_delete_all_data(bus_station* bs);

// �������� ��������� ������:
void console_menu_option_delete_choosen_data(bus_station* bs);




// ����������� �������:




// �������� ���� ������:
void console_menu_option_delete_all_data(bus_station* bs) {


	cout << "\t�������� ���� ������\n\n";


	// ���������� ����������:

	string user_input; // ���������������� ����


	// ���� ���� ������ �� ����� (������ ������ �� ���������):
	if (!is_data_base_holding_empty_list(bs)) {


		// ����� �� ����� �������������� � ��������� ������ ������ � ������������ ��������� � ����:
		cout << "- ��������������: � ���� ������ ��� �������� ������ �� ���������.\n"
			"�� �������, ��� ������ �� ������� (1) ��� �������� ��������� � ���� (2)?\n\n";


		// ������� �� ������������ �����, ����� �� �� ��������� � ����:
		user_input = get_user_input_with_conditions(0, "is_1_or_2"); // ��������� �� ������������ ������ � ��������� �� ������������: ������� �� ������� ��� ������


		// ���� ������������ ������ ��������� � ����, �� ���������� ��� � ����:
		if (user_input == "2") {


			return; // ��������� ���������� ������� ���� void, ��������� �� ����� ����. ������������ � ���� ����.


		} // ����� ����� "���� ������������ ������ ��������� � ����, �� ���������� ��� � ����"


	} // ����� ����� "���� ���� ������ �� ����� (������ ������ �� ���������)"


	// �������� ������� �������� ���� ������ ��� ��������� ������������ ������, ���� ����� ��� ������ ���������� � ��:
	// ����������: ������� ��� �� ������ � ��� ������ �� ����� �������� ������ � ��� ������ �� ����� �������� ������
	if (bs->bus_station_type_of_list == '1') delete_all_data(bs->bus_station_buses_linear_singly_linked_list);

	// � ������ ������������ ������, �������� � �� �� ������� ��������� �� ����������� ������, ���������� � ��:
	else delete_all_data(bs->bus_station_buses_linear_doubly_linked_list);


} // ����� ����� "�������� ���� ������"




// �������� ��������� ������:
void console_menu_option_delete_choosen_data(bus_station* bs) {


	cout << "\t�������� ��������� ������\n\n";


	// ���������� ����������:

	int n = 7; // ����� ���������� �������� 

	int delete_parameter; // ����� ��������� ��������, ��������� ������������� (�� 1 �� 7)

	string delete_key; // �������� ��������� ��������, �� �������� ����� ��������� ������


	cout << "- �� ����� �������� ������� ������?\n";


	cout << "����������� (1)"
		<< " / " << "����� ����� (2)"
		<< " / " << "����� �������� (3)"
		<< " / " << "����� ����������� (4)"
		<< " / " << "��� �������� (5)"
		<< " / " << "����� ��������� ������� (6)"
		<< " / " << "��������� ����� ���������� (7)\n\n";


	// ���������� �� ������������ ������ ��������� �������� � ��������� �� ������������: ���� �� ������� ����������� �����:
	delete_parameter = stoi(get_user_input_with_conditions(n + 1, "lower_then_n")); 


	// � ����������� �� ������ ��������� ��������, ��������� �������� ��������
	// (� ������ ���������� ������ ������ �����)
	switch (delete_parameter) {

	case 1:
		cout << "������� �����������. ";
		cin >> delete_key;
		break;
	case 3:
		cout << "������� ����� ��������: ";
		cin >> delete_key;
		break;
	case 4:
		cout << "������� ����� �����������: ";
		cin >> delete_key;
		break;
	case 5:
		cout << "������� ��� ��������: ";
		cin.ignore();
		getline(cin, delete_key);
		break;
	case 2:
		cout << "������� ����� �����. ";
		delete_key = get_user_input_with_conditions(0, "natural_number");
		break;
	case 6:
		cout << "������� ����� ��������� �������. ";
		delete_key = get_user_input_with_conditions(0, "natural_number");
		break;
	case 7:
		cout << "������� ��������� ����� ����������. ";
		delete_key = get_user_input_with_conditions(0, "natural_number");
		break;
	default:
		cout << "error";
		return;

	} // ����� ����� "� ����������� �� ������ ��������� ��������, ��������� �������� ��������"


	cout << "\n������� �������� �� �������� ���������...\n\n";


	bool flag = false; // ��� �� ������ ���� �� ���� �������
	bool deliting = false; // ������� �� ���� �������
	

	// �������� ����������� ������, �������� ��������� ���������:
	if (bs->bus_station_type_of_list == '1') {


		// �������� ����������-�������� ��� "��������" �� ������:
		bus_from_linear_singly_linked_list* iterator_bus = new bus_from_linear_singly_linked_list;  


		// ��������� �� �� ������ ������, �.�. ��� ����� ��������� �� ������ ������� ������.
		// ����� �������, ������� �� ����� �� ������� �������, � ���������, �� ��� �� ��������� ��� �������� �� ������, ����
		// ������ �� � ������� ��������, � � "������������" ����� ������ ��������.
		iterator_bus->bus_next_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;


		// ���� ������� �� ������:
		while (iterator_bus->bus_next_bus != NULL) {


			// � ����������� �� ������ ��������� ��������, ������ ��������������� ��������� � ������� ��������:
			switch (delete_parameter) {


			case 1: // ����� ��������� �������� ������������� "�����������"

				// ���� � ���������� �������� "�����������" ����� ���������� �������������, �� ������� ��������� �������:
				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_destination) deliting = true; 
				break;

			case 2: // ���������� ...

				// ����������...
				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_passage_number) deliting = true;
				break;

			case 3: // ... 

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_brand) deliting = true;
				break;

			case 4:

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_departure_time) deliting = true;
				break;

			case 5:

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_full_name_of_the_driver) deliting = true;
				break;

			case 6:

				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_number_of_tickets_sold) deliting = true;
				break;

			case 7:

				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_estimated_number_of_passengers) deliting = true;
				break;

			default:

				cout << "Error in delete function";
				exit(1);

			} // ����� ����� "� ����������� �� ������ ��������� ��������, ������ ��������������� ��������� � ������� ��������"


			// �������� ��������
			if (deliting) {

				
				cout << "\n������� �������: ";


				// �������� �������:
				output_bus_to_console(iterator_bus->bus_next_bus);


				// ���� ��������� ������� - ��� ������ � ������:
				if (iterator_bus->bus_next_bus == bs->bus_station_buses_linear_singly_linked_list->buses_first_bus) {

					// ������� ��������� �� ������ ������ �� ��������� ������� (��� �� NULL):
					bs->bus_station_buses_linear_singly_linked_list->buses_first_bus = iterator_bus->bus_next_bus->bus_next_bus;

				}


				// ������� �������:
				delete_next_bus(iterator_bus);


				flag = true; // ��� ������ ���� ���� �������
				deliting = false; // ���� ���� ������ ������ false � ������ ������� ������� �����, �� ����������, ����� �� ��������


			} // ����� ����� "�������� ��������"

			// ���� ������ �� ������
			iterator_bus = iterator_bus->bus_next_bus;

		} // ����� ���� "���� ������� �� ������"



	} // ����� ����� "�������� ����������� ������, �������� ��������� ���������"

	// �������� ����������� ������, �������� ��������� ���������:
	else {


		// �������� ����������-�������� ��� "��������" �� ������:
		bus_from_linear_doubly_linked_list* iterator_bus = new bus_from_linear_doubly_linked_list;


		// ��������� �� �� ������ ������, �.�. ��� ����� ��������� �� ������ ������� ������.
		// ����� �������, ������� �� ����� �� ������� �������, � ���������, �� ��� �� ��������� ��� �������� �� ������, ����
		// ������ �� � ������� ��������, � � "������������" ����� ������ ��������.
		iterator_bus->bus_next_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;


		// ���� ������� �� ������:
		while (iterator_bus->bus_next_bus != NULL) {


			// � ����������� �� ������ ��������� ��������, ������ ��������������� ��������� � ������� ��������:
			switch (delete_parameter) {


			case 1: // ����� ��������� �������� ������������� "�����������"

				// ���� � ���������� �������� "�����������" ����� ���������� �������������, �� ������� ��������� �������:
				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_destination) deliting = true;
				break;

			case 2: // ���������� ...

				// ����������...
				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_passage_number) deliting = true;
				break;

			case 3: // ... 

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_brand) deliting = true;
				break;
			
			case 4:

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_departure_time) deliting = true;
				break;
			
			case 5:

				if (delete_key == iterator_bus->bus_next_bus->bus_data->bus_full_name_of_the_driver) deliting = true;
				break;

			case 6:

				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_number_of_tickets_sold) deliting = true;
				break;

			case 7:

				if (stoi(delete_key) == iterator_bus->bus_next_bus->bus_data->bus_estimated_number_of_passengers) deliting = true;
				break;

			default:

				cout << "Error in delete function";
				exit(1);

			} // ����� ����� "� ����������� �� ������ ��������� ��������, ������ ��������������� ��������� � ������� ��������"


			// �������� ��������:
			if (deliting) {


				cout << "\n������� �������: ";


				// �������� �������:
				output_bus_to_console(iterator_bus->bus_next_bus);


				// ���� ��������� ������� - ��� ������ � ������:
				if (iterator_bus->bus_next_bus == bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus) {

					// ������� ��������� �� ������ ������ �� ��������� ������� (��� �� NULL):
					bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus = iterator_bus->bus_next_bus->bus_next_bus;

				}


				// ������� �������:
				delete_next_bus(iterator_bus);
				flag = true;
				deliting = false;


			} // ����� ����� "�������� ��������"


			// ���� ������ �� ������
			iterator_bus = iterator_bus->bus_next_bus;


		} // ����� ���� "���� ������� �� ������"


	} // ����� ����� "�������� ����������� ������, �������� ��������� ���������"


	// ���� �� ��� ������ �� ���� �������:
	if (!flag) cout << "\n�� ���� ��������� �� ��� ������...\n\n";


	// ���� ��� ������ ���� �� ���� �������, �������� �������� ���������� ����� �������� ���� ������:
	else {


		// �������� ����������� ������:
		if (bs->bus_station_type_of_list == '1') save_all_buses_to_storage_file(bs->bus_station_buses_linear_singly_linked_list);


		// �������� ����������� ������:
		else save_all_buses_to_storage_file(bs->bus_station_buses_linear_doubly_linked_list);


	}


} // ����� ������� "�������� ��������� ������"
