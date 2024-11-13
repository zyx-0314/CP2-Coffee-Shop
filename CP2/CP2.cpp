#include <iostream>
#include <string>

void Problem1();
int P1_MainMenu();
int P1_ReservationChoice(
	const int, 
	int, 
	int id[], 
	std::string, 
	bool,
	std::string customerName[], 
	std::string order[]
);
std::string P1_OrderChoice();
std::string P1_AddString(std::string);
int P1_ToUpdate();
void Traverse(
	int id[], 
	std::string customerName[], 
	std::string order[], 
	const int,
	bool
);

int main()
{
	Problem1();
}

void Problem1() {
	/*
		Create a system that can
		accomodate customer of cafe,
		cafe has only 10 slots of seats
		to reserve.owner requires a
		name and order of client to be
		reserve in that seat
	*/

	const int MAX = 10;
	int id[MAX], clientCounterOfTheDay = 0;
	std::string customerName[MAX], order[MAX];

	while (true)
	{
		switch (P1_MainMenu())
		{
		case 1:
			while (true)
			{
				int reserve = P1_ReservationChoice(
					MAX,
					clientCounterOfTheDay,
					id,
					"Reservation",
					false,
					customerName, 
					order
				);

				if (!reserve) break;

				reserve--;

				if (0 < id[reserve])
				{
					std::cout << "this is occupied\n";
					system("pause");
				}
				else
				{
					clientCounterOfTheDay++;
					id[reserve] = clientCounterOfTheDay;
					std::cin.ignore();
					customerName[reserve] = P1_AddString("Add Client Name:");
					order[reserve] = P1_OrderChoice();
					break;
				}
			}
			break;
		case 2:
			while (true)
			{
				int reserve = P1_ReservationChoice(
					MAX,
					clientCounterOfTheDay,
					id,
					"Reservation",
					true,
					customerName,
					order
				);

				if (!reserve) break;

				reserve--;

				if (0 > id[reserve])
				{
					std::cout << "this is vaccant\n";
					system("pause");
				}
				else
				{
					id[reserve] = 0;
					customerName[reserve] = "";
					order[reserve] = "";
					break;
				}
			}
			break;
		case 3:
			while (true)
			{
				int reserve = P1_ReservationChoice(
					MAX,
					clientCounterOfTheDay,
					id,
					"Reservation",
					true,
					customerName,
					order
				);

				if (!reserve) break;

				reserve--;

				if (0 > id[reserve])
				{
					std::cout << "this is not occupied\n";
					system("pause");
				}
				else
				{
					int choice = P1_ToUpdate();

					if (choice == 1 || choice == 3) {
						std::cin.ignore();
						std::cout << "\nOld Client Name: " << customerName[reserve] << std::endl;
						customerName[reserve] = P1_AddString("Update Client Name:");
					}

					if (choice == 1 || choice == 2) {
						std::cout << "\nOld Order: " << order[reserve] << std::endl;
						order[reserve] = P1_OrderChoice();
					}

					if (!choice) {
						break;
					}
				}
			}
			break;
		case 4:
			system("cls");
			Traverse(id, customerName, order, MAX, true);
			Traverse(id, customerName, order, MAX, false);
			system("pause");
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
}

int P1_MainMenu() {
	int choice = 0;

	system("cls");

	while (choice > 4 || choice < 1)
	{
		std::cout
			<< "Main Menu\n"
			<< "1. Reserve Seat\n"
			<< "2. Check out Client\n"
			<< "3. Update\n"
			<< "4. List of Reservations\n"
			<< "0. Exit\n"
			<< "\n"
			<< "::"
			;
		std::cin >> choice;
	}

	return choice;
}

int P1_ToUpdate() {
	int choice = -1;

	system("cls");

	while (choice > 3 || choice < 0)
	{
		std::cout
			<< "Main Menu\n"
			<< "1. All\n"
			<< "2. Order\n"
			<< "3. Name\n"
			<< "0. Exit\n"
			<< "\n"
			<< "::"
			;
		std::cin >> choice;
	}

	return choice;
}

int P1_ReservationChoice(
	const int MAX,
	int clientCounterOfTheDay,
	int id[],
	std::string config,
	bool occupied,
	std::string customerName[],
	std::string order[]
) {
	int choice = -1;

	system("cls");

	while (choice > MAX || choice < 0)
	{
		std::cout
			<< config << " Main Menu\n"
			<< "Choose from choices below\n"
			;
		Traverse(id, customerName, order, MAX, occupied);
		std::cout
			<< "0. Exit\n"
			<< "\n"
			<< "::"
			;
		std::cin >> choice;
	}

	return choice;
}

std::string P1_OrderChoice() {
	int choiceInt = -1;

	while (choiceInt > 4 || choiceInt < 0)
	{
		std::cout
			<< "Main Menu\n"
			<< "1. Coffee\n"
			<< "2. Tea\n"
			<< "3. Milk Tea\n"
			<< "4. Water Melon\n"
			<< "0. Cancel"
			<< "\n"
			<< "::"
			;
		std::cin >> choiceInt;
	}

	switch (choiceInt)
	{
	case 1:
		return "Coffee";
		break;
	case 2:
		return "Tea";
		break;
	case 3:
		return "Milk Tea";
		break;
	case 4:
		return "Water Melon";
		break;
	case 0:
		return "";
		break;
	}
}

std::string P1_AddString(std::string instruction) {
	std::string input;
	std::cout << instruction;
	std::getline(std::cin, input);

	return input;
}

void Traverse(
	int id[],
	std::string	customerName[],
	std::string order[],
	const int MAX,
	bool occupied
)
{
	if (occupied) {
		std::cout 
			<< "\n\n"
			<< "Occupied\n";
		for (size_t i = 0; i < MAX; i++)
		{
			if (id[i] > 0) {
				std::cout << i + 1 << ". " << customerName[i] << " - " << order[i] << std::endl;
			}
		}
		std::cout << "\n\n";
	}
	else {
		std::cout
			<< "\n\n"
			<< "Vaccant\n";
		for (size_t i = 0; i < MAX; i++)
		{
			if (id[i] <= 0) {
				std::cout << "| " << i + 1;
			}
		}
		std::cout << "|\n\n";
	}
}
