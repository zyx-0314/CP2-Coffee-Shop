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
		// 1. Display the Main menu function for accepting choice of the user
		switch (P1_MainMenu())
		{
		case 1:
			while (true)
			{
				// 2.1.1 Sets the reserve choice
				int reserve = P1_ReservationChoice(
					MAX,
					clientCounterOfTheDay,
					id,
					"Reservation",
					false,
					customerName, 
					order
				);

				// 2.1.2 If the return value is 0(false) it will stop the loop
				if (!reserve) break;

				// 2.1.3 It will set the value to computers couting mechanism
				// 1 for human = 0 for computer
				reserve--;

				// 2.1.4 Checking if the id based on the reserve has a higher value than 0
				if (0 < id[reserve])
				{
					// 2.1.4.1 It will inform the user that it is occupied
					std::cout << "this is occupied\n";
					system("pause");
				}
				else
				{
					// 2.1.4.2.1 clientCounterOfTheDay will add 1
					clientCounterOfTheDay++;
					// 2.1.4.2.2 id based on reserve will store the clientCounterOfTheDay
					id[reserve] = clientCounterOfTheDay;
					std::cin.ignore();
					// 2.1.4.2.3 ask user to input clients name
					customerName[reserve] = P1_AddString("Add Client Name:");
					// 2.1.4.2.4 store the return value
					order[reserve] = P1_OrderChoice();
					// 2.1.4.2.5 it will stop the loop
					break;
				}
			}
			break;
		case 2:
			while (true)
			{
				// 2.2.1 Set the reserve choice
				int reserve = P1_ReservationChoice(
					MAX,
					clientCounterOfTheDay,
					id,
					"Reservation",
					true,
					customerName,
					order
				);

				// 2.2.2 If the return value is 0(false) it will stop the loop
				if (!reserve) break;

				// 2.2.3 It will set the value to computers couting mechanism
				// 1 for human = 0 for computer
				reserve--;

				// 2.2.4 Checking if the id based on the reserve is lower than 0
				if (0 > id[reserve])
				{
					// 2.2.4.1 It will inform the user that it is vaccant
					std::cout << "this is vaccant\n";
					system("pause");
				}
				else
				{
					// 2.2.4.2.1 It will reset to 0/""/blank
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
				// 2.3.1 Set the reserve choice
				int reserve = P1_ReservationChoice(
					MAX,
					clientCounterOfTheDay,
					id,
					"Reservation",
					true,
					customerName,
					order
				);

				// 2.3.1 If the return value is 0(false) it will stop the loop
				if (!reserve) break;

				// 2.3.3 It will set the value to computers couting mechanism
				// 1 for human = 0 for computer
				reserve--;

				// 2.3.4  Checking if the id based on the reserve has a higher value than 0
				if (0 > id[reserve])
				{
					// 2.3.4.1 Checking if the id based on the reserve has a higher value than 0
					std::cout << "this is not occupied\n";
					system("pause");
				}
				else
				{
					// 2.3.4.2 Set the value of choice
					int choice = P1_ToUpdate();

					// 2.3.4.3 If the value is 1 or 3
					if (choice == 1 || choice == 3) {
						std::cin.ignore();
						// 2.3.4.3.1 Display old client name
						std::cout << "\nOld Client Name: " << customerName[reserve] << std::endl;
						// 2.3.4.3.2 Set the new customer name
						customerName[reserve] = P1_AddString("Update Client Name:");
					}

					// 2.3.4.4 If the value is 1 or 2
					if (choice == 1 || choice == 2) {
						// 2.3.4.4.1 Display old client order
						std::cout << "\nOld Order: " << order[reserve] << std::endl;
						// 2.3.4.4.2 Set the new customer order
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
			// 2.4.1 Display the occupied seat
			Traverse(id, customerName, order, MAX, true);
			// 2.4.2 Display the vaccant seat
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

	// 3. It will do the loop again if not in choice
	while (choice > 4 || choice < 1)
	{
		// 1. This will display the possible choices
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
		// 2. User Can Input their chocei
		std::cin >> choice;
	}

	// 4. Return choice selected when it pass the 3rd step
	return choice;
}

int P1_ToUpdate() {
	int choice = -1;

	system("cls");

	// 3. Check if the user input is within 0 - 3
	while (choice > 3 || choice < 0)
	{
		// 1. Display the options
		std::cout
			<< "Main Menu\n"
			<< "1. All\n"
			<< "2. Order\n"
			<< "3. Name\n"
			<< "0. Exit\n"
			<< "\n"
			<< "::"
			;
		// 2. Input of user
		std::cin >> choice;
	}


	// 4. return value of choice
	return choice;
}

// 1. It requires 
int P1_ReservationChoice(
	const int MAX,					// Maximum number of list
	int clientCounterOfTheDay,		// Current client of the day
	int id[],						// Queue number
	std::string config,				// UI Name
	bool occupied,					// Either display occupied/vaccant
	std::string customerName[],		// List of customer name
	std::string order[]				// List of orders
) {
	int choice = -1;

	system("cls");

	// 6. Check if within the 0 and MAX
	while (choice > MAX || choice < 0)
	{
		// 2. Display Partial of the menu for choices
		std::cout
			<< config << " Main Menu\n"
			<< "Choose from choices below\n"
			;
		// 3. Display the current list of occuppied/vacant
		Traverse(id, customerName, order, MAX, occupied);
		// 4. Continuation of the menu
		std::cout
			<< "0. Exit\n"
			<< "\n"
			<< "::"
			;
		// 5. Input by user
		std::cin >> choice;
	}

	// 7. Return the choice
	return choice;
}

std::string P1_OrderChoice() {
	int choiceInt = -1;

	while (choiceInt > 4 || choiceInt < 0)
	{
		// 1. Display order menu 
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
		// 2. user input
		std::cin >> choiceInt;
	}

	// 3. return the equivalent of the choiceInt
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

// Input string
std::string P1_AddString(std::string instruction) {
	std::string input;
	std::cout << instruction;
	std::getline(std::cin, input);

	return input;
}

// 1. It requires
void Traverse(
	int id[],					// Queue Number
	std::string	customerName[],	// List of Customer Name
	std::string order[],		// List of Orders
	const int MAX,				// Maximum Of the List
	bool occupied				// Displays vaccant/occupied
)
{
	// 2.1 Display all Occupied Data
	if (occupied) {
		// 2.1.1 Display the configuration 
		std::cout 
			<< "\n\n"
			<< "Occupied\n";
		// 2.1.2 Loop onto the list array
		for (size_t i = 0; i < MAX; i++)
		{
			// 2.1.3 if it is greater than 0 then it means it is occupied
			if (id[i] > 0) {
				// 2.1.4 displays the information in the list and adjust number that indicates their index
				std::cout << i + 1 << ". " << customerName[i] << " - " << order[i] << std::endl;
			}
		}
		std::cout << "\n\n";

	}
	// 2.2 Display all vacant
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