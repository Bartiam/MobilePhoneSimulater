#include "phone.h"

bool is_correct_command(const std::string& command)
{
	if (command != "Add" && command != "add" &&
		command != "Call" && command != "call" &&
		command != "Sms" && command != "sms" &&
		command != "Exit" && command != "exit") return false;

	return true;
}

int main()
{
	std::string command;
	std::string name;
	std::string wasAdd;
	std::string phoneNumber;
	Phone myPhone;

	while (true)
	{
		wasAdd = " ";
		std::cout << "Enter the command: " << std::endl;
		std::cin >> command;

		if (command == "Add" || command == "add")
		{
			while (wasAdd != "add")
			{
				std::cout << "Enter the name of the contact(Format: Andrey): ";
				std::cin >> name;

				std::cout << "Enter the phone number of the contact(Format: +71112223334): ";
				std::cin >> phoneNumber;

				wasAdd = myPhone.add(name, phoneNumber);
			}
		}
		else if (command == "Call" || command == "call")
		{
			std::cout << "Enter name or phone number: ";
			std::cin >> name;

			myPhone.call(name);
		}
		else if (command == "Sms" || command == "sms")
		{
			std::cout << "Enter name or phone number: ";
			std::cin >> name;

			myPhone.send_message(name);
		}
		else if (command == "Exit" || command == "exit") return 0;
		else if (!is_correct_command(command))
			std::cerr << "Error! You can enter only available commands. " <<
			"\nList of available commands: " <<
			"\nPlay, Pause, Next, Stop, Exit. " << std::endl;
	}

	return 0;
}
