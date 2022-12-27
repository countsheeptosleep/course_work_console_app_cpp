#include <string>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "structures_definition.h"
#include "menu_options_group_of_output.h"
#include "group_output.h"
#include "constants.h"

void sort(string sort_mode, int choosen_option, bus_station* bs);

void sort(string sort_mode, int choosen_option, bus_station* bs) {


	// �������� ����������: ����� ���������� ��� �������� ������ ���������������.
	// ������ ������� ����� ���������� �� ����� ����������� � ����������� ��� � ��������������� �������.
	// �� ���� �� ������ ���� ����� �������� ��������������� ������� ������, � � ������ ���� ���� �������
	// ����� ������������� � ����� �� �������.
	// ��� ��� ������ ���� �� ��������, � �� � ���������, �� ���������� ������� ��������� �� ������ ������
	// ����� ���������� ����������, ������ � ���� ����� ��������� �������������� ���������� ��� 
	// ������������ ����������� � �������� ��������� ���������� ���������.


	// ������ ��������� ������������ ������:
	if (bs->bus_station_type_of_list == '1') {

		// �������� ��������, ������������ ��� �������� ���� ��������� ������.
		// �������� ����� ��������� �� ������ �������� ��������� � ����������� � ��������������� ����� ������.
		// ����� ����� �������� ����� ����� ���������� ���������������� ��������:
		bus_from_linear_singly_linked_list* iterator_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus->bus_next_bus;

		// ����� ����� �������� ���������:
		bus_from_linear_singly_linked_list* mesto_pered_vstavkoi_iterator;

		// ����� ����� �������� ���������:
		bus_from_linear_singly_linked_list* mesto_posle_udaleniya_iterator;

		// ����� ����� ��������� ���������:
		bus_from_linear_singly_linked_list* mesto_pered_udaleniem_iterator;


		// �������� ���� ������:
		while (iterator_bus != NULL) {


			// ����� ����� �������� ���������. ���������� ��������� �� ������ ������� � ������,
			// �� ���� ��� �� ��������� �� ������ ������:
			mesto_pered_vstavkoi_iterator = new bus_from_linear_singly_linked_list;
			mesto_pered_vstavkoi_iterator->bus_next_bus = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;


			// � ����������� �� ��������� ����� ����������, � ����� ����������� (�����������, ��������)
			// ���� ����� � ��������������� ����� ������ ��� ������� ���������������� ��������:
			switch (choosen_option) {

			case 1: // "�����������"

				if (sort_mode == "1") { // �� �����������

					// ���� �� ����� ����� ��� ������� ��� �� ���������� �� ���� �� �������:
					while (iterator_bus->bus_data->bus_destination > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_destination
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						// ����������� "����� ����� ��������" ������
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else { // �� ��������

					// ����� ��� ����������...

					while (iterator_bus->bus_data->bus_destination < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_destination
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 2:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_passage_number > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_passage_number
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;
					}

				}

				else {

					while (iterator_bus->bus_data->bus_passage_number < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_passage_number
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;
					}

				}

				break;

			case 3:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_brand > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_brand
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_brand < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_brand
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 4:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_departure_time > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_departure_time
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_departure_time < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_departure_time
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 5:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_full_name_of_the_driver > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_full_name_of_the_driver
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_full_name_of_the_driver < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_full_name_of_the_driver
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 6:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_number_of_tickets_sold > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_number_of_tickets_sold
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_number_of_tickets_sold < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_number_of_tickets_sold
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 7:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_estimated_number_of_passengers > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_estimated_number_of_passengers
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_estimated_number_of_passengers < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_estimated_number_of_passengers
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;


			} // ����� ����� "// � ����������� �� ��������� ����� ����������, � ����� ����������� (�����������, ��������)
			// ���� ����� � ��������������� ����� ������ ��� ������� ���������������� ��������"


			// ���� ��������������� ������� � ��� ����� �� ����� ����� � ��������������� ����� ������:
			if (mesto_pered_vstavkoi_iterator->bus_next_bus == iterator_bus) {

				// ������ ��������� � ������������ ���������� ��������
				iterator_bus = iterator_bus->bus_next_bus;

			}

			// ����� ������ ������������ "���������" �� ��� "�����-�������"...
			else {

				// ������ "����� ����� ��������� ���������" � �������� ��� � ��� ����������:
				mesto_pered_udaleniem_iterator = new bus_from_linear_singly_linked_list;
				mesto_pered_udaleniem_iterator = bs->bus_station_buses_linear_singly_linked_list->buses_first_bus;
				while (mesto_pered_udaleniem_iterator->bus_next_bus != iterator_bus) {
					mesto_pered_udaleniem_iterator = mesto_pered_udaleniem_iterator->bus_next_bus;
				}

				// ���� ����� ��������� �������� �� ����� ������� �������� ������, �� 
				// ����� ������� �������� ������ ��������� � ������ (��������� �� ���� ��������� first_bus)
				if (mesto_pered_vstavkoi_iterator->bus_next_bus == bs->bus_station_buses_linear_singly_linked_list->buses_first_bus) {
					bs->bus_station_buses_linear_singly_linked_list->buses_first_bus = iterator_bus;
				}


				// �������� "����� ����� �������� ���������"
				mesto_posle_udaleniya_iterator = iterator_bus->bus_next_bus;


				// ��������� �������� � ��������� �����:
				iterator_bus->bus_next_bus = mesto_pered_vstavkoi_iterator->bus_next_bus;
				mesto_pered_vstavkoi_iterator->bus_next_bus = iterator_bus;


				// ����� ��������� ��������� ������������� �� ��������� ������� � ������.
				// ������������ ������� ��� ���� �������� �� ����� �����:
				iterator_bus = mesto_posle_udaleniya_iterator;


				// ����� ����� ��������� ��������� ������ ���������� �� ����� ����� ��������,
				// ���� �� �������� ��� �������, �� ����� ���������� �� ����� ����� ���������:
				mesto_pered_udaleniem_iterator->bus_next_bus = mesto_posle_udaleniya_iterator;


			} // ����� ����� "����� ������ ������������ "���������" �� ��� "�����-�������""


		} // ����� ����� "�������� ���� ������"


	} // ����� ����� "������ ��������� ������������ ������"


	else { // ������ ��������� ������������ ������

		// �������� ��������, ������������ ��� �������� ���� ��������� ������.
		// �������� ����� ��������� �� ������ �������� ��������� � ����������� � ��������������� ����� ������.
		// ����� ����� �������� ����� ����� ���������� ���������������� ��������:
		bus_from_linear_doubly_linked_list* iterator_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus->bus_next_bus;

		// ����� ����� �������� ���������:
		bus_from_linear_doubly_linked_list* mesto_pered_vstavkoi_iterator;

		// ����� ����� �������� ���������:
		bus_from_linear_doubly_linked_list* mesto_posle_udaleniya_iterator;

		// ����� ����� ��������� ���������:
		bus_from_linear_doubly_linked_list* mesto_pered_udaleniem_iterator;

		// �������� ���� ������:
		while (iterator_bus != NULL) {


			// ����� ����� �������� ���������. ���������� ��������� �� ������ ������� � ������,
			// �� ���� ��� �� ��������� �� ������ ������:
			mesto_pered_vstavkoi_iterator = new bus_from_linear_doubly_linked_list;
			mesto_pered_vstavkoi_iterator->bus_next_bus = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;


			// � ����������� �� ��������� ����� ����������, � ����� ����������� (�����������, ��������)
			// ���� ����� � ��������������� ����� ������ ��� ������� ���������������� ��������:
			switch (choosen_option) {

			case 1: // "�����������"

				if (sort_mode == "1") { // �� �����������

					// ���� �� ����� ����� ��� ������� ��� �� ���������� �� ���� �� �������:
					while (iterator_bus->bus_data->bus_destination > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_destination
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						// ����������� "����� ����� ��������" ������
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else { // �� ��������

					while (iterator_bus->bus_data->bus_destination < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_destination
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 2: // ���������� ...

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_passage_number > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_passage_number
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;
					}

				}

				else {

					while (iterator_bus->bus_data->bus_passage_number < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_passage_number
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {
						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;
					}

				}

				break;

			case 3:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_brand > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_brand
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_brand < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_brand
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 4:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_departure_time > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_departure_time
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_departure_time < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_departure_time
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 5:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_full_name_of_the_driver > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_full_name_of_the_driver
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_full_name_of_the_driver < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_full_name_of_the_driver
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 6:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_number_of_tickets_sold > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_number_of_tickets_sold
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_number_of_tickets_sold < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_number_of_tickets_sold
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;

			case 7:

				if (sort_mode == "1") {

					while (iterator_bus->bus_data->bus_estimated_number_of_passengers > mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_estimated_number_of_passengers
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				else {

					while (iterator_bus->bus_data->bus_estimated_number_of_passengers < mesto_pered_vstavkoi_iterator->bus_next_bus->bus_data->bus_estimated_number_of_passengers
						&& mesto_pered_vstavkoi_iterator->bus_next_bus != iterator_bus) {

						mesto_pered_vstavkoi_iterator = mesto_pered_vstavkoi_iterator->bus_next_bus;

					}

				}

				break;


			} // ����� ����� "// � ����������� �� ��������� ����� ����������, � ����� ����������� (�����������, ��������)
			// ���� ����� � ��������������� ����� ������ ��� ������� ���������������� ��������"


			// ���� ��������������� ������� � ��� ����� �� ����� ����� � ��������������� ����� ������:
			if (mesto_pered_vstavkoi_iterator->bus_next_bus == iterator_bus) {

				// ������ ��������� � ������������ ���������� ��������
				iterator_bus = iterator_bus->bus_next_bus;

			}

			// ����� ������ ������������ "���������" �� ��� "�����-�������"...
			else {


				// ������ "����� ����� ��������� ���������" � �������� ��� � ��� ����������:
				mesto_pered_udaleniem_iterator = new bus_from_linear_doubly_linked_list;
				mesto_pered_udaleniem_iterator = bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus;
				while (mesto_pered_udaleniem_iterator->bus_next_bus != iterator_bus) {
					mesto_pered_udaleniem_iterator = mesto_pered_udaleniem_iterator->bus_next_bus;
				}


				// ���� ����� ��������� �������� �� ����� ������� �������� ������, �� 
				// ����� ������� �������� ������ ��������� � ������ (��������� �� ���� ��������� first_bus)
				if (mesto_pered_vstavkoi_iterator->bus_next_bus == bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus) {
					bs->bus_station_buses_linear_doubly_linked_list->buses_first_bus = iterator_bus;
				}


				// �������� "����� ����� �������� ���������"
				mesto_posle_udaleniya_iterator = iterator_bus->bus_next_bus;


				// ��������� �������� � ��������� �����:
				iterator_bus->bus_next_bus = mesto_pered_vstavkoi_iterator->bus_next_bus;
				iterator_bus->bus_next_bus->bus_previous_bus = iterator_bus;
				iterator_bus->bus_previous_bus = mesto_pered_vstavkoi_iterator;
				mesto_pered_vstavkoi_iterator->bus_next_bus = iterator_bus;


				// ����� ��������� ��������� ������������� �� ��������� ������� � ������.
				// ������������ ������� ��� ���� �������� �� ����� �����:
				iterator_bus = mesto_posle_udaleniya_iterator;


				// ����� ����� ��������� ��������� ������ ���������� �� ����� ����� ��������,
				// ���� �� �������� ��� �������, �� ����� ���������� �� ����� ����� ���������:
				mesto_pered_udaleniem_iterator->bus_next_bus = mesto_posle_udaleniya_iterator;
				if (mesto_posle_udaleniya_iterator != NULL) mesto_posle_udaleniya_iterator->bus_previous_bus = mesto_pered_udaleniem_iterator;

			} // ����� ����� "����� ������ ������������ "���������" �� ��� "�����-�������""

		} // ����� ����� "�������� ���� ������"


	} // ����� ����� "������ ��������� ������������ ������"

	// �������������� ���������� ������ � ����� �������� ��:

	// �������� ����������� ������:
	if (bs->bus_station_type_of_list == '1') save_all_buses_to_storage_file(bs->bus_station_buses_linear_singly_linked_list);

	// �������� ����������� ������:
	else save_all_buses_to_storage_file(bs->bus_station_buses_linear_doubly_linked_list);


} // ����� ������� ����������