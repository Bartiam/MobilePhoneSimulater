#include "phone.h"

std::string Contact::getName() {return name;}

std::string Contact::getPhoneNumber() {return phoneNumber;}

void Contact::setName(const std::string& name) {this->name = name;}

void Contact::setPhoneNumber(const std::string& phoneNumber) {this->phoneNumber = phoneNumber;}

bool Phone::phone_number_format(const std::string& phoneNumber)
{
	if (phoneNumber.length() != 12) return false;
	if (phoneNumber[0] != '+' || phoneNumber[1] != '7') return false;
	for (int i = 2; i < phoneNumber.length(); ++i)
		if (phoneNumber[i] < '0' || phoneNumber[i] > '9') return false;

	return true;
}

bool Phone::name_format(const std::string& name)
{
	if (name[0] < 'A' || name[0] > 'Z') return false;
	for (int i = 1; i < name.length(); ++i)
		if (name[i] < 'a' || name[i] > 'z') return false;

	return true;
}

void Phone::send_message(const std::string& nameOrPhoneNumber)
{
	system("cls");
	if (nameOrPhoneNumber.empty())
	{
		std::cerr << "Error! Name and phone number is empty. Try again. " << std::endl;
		return;
	}
	
	if (name_format(nameOrPhoneNumber))
	{
		if (contacts.empty())
		{
			std::cout << "The contact list is empty. " << std::endl;
			return;
		}

		for (int i = 0; i < contacts.size(); ++i)
		{
			if (contacts[i].getName() == nameOrPhoneNumber)
			{
				std::cout << "A message has been sent to the contact: " <<
					"\nName: " << contacts[i].getName() <<
					"\nPhone number: " << contacts[i].getPhoneNumber() << std::endl;
				return;
			}
		}

		std::cerr << "Error! There is no such contact named \"" <<
			nameOrPhoneNumber << " in the list. Try again. " << std::endl;
	}
	else if (phone_number_format(nameOrPhoneNumber))
	{
		if (contacts.empty())
		{
			std::cout << "The contact list is empty. " << std::endl;
			return;
		}

		for (int i = 0; i < contacts.size(); ++i)
		{
			if (contacts[i].getPhoneNumber() == nameOrPhoneNumber)
			{
				std::cout << "A message has been sent to the contact: " <<
					"\nName: " << contacts[i].getName() <<
					"\nPhone number: " << contacts[i].getPhoneNumber() << std::endl;
				return;
			}
		}

		std::cerr << "Error! A contact with such a phone number \"" <<
			nameOrPhoneNumber << "\" is not in the list. " << std::endl;
	}
}

void Phone::call(const std::string& nameOrPhoneNumber)
{
	system("cls");
	if (nameOrPhoneNumber.empty())
	{
		std::cerr << "Error! Name and phone number is empty. Try again. " << std::endl;
		return;
	}

	if (name_format(nameOrPhoneNumber))
	{
		if (contacts.empty())
		{
			std::cout << "The contact list is empty. " << std::endl;
			return;
		}

		for (int i = 0; i < contacts.size(); ++i)
		{
			if (contacts[i].getName() == nameOrPhoneNumber)
			{
				std::cout << "The call was made to the contact: " <<
					"\nName: " << contacts[i].getName() <<
					"\nPhone number: " << contacts[i].getPhoneNumber() << std::endl;
				return;
			}
		}

		std::cerr << "Error! There is no such contact named \"" <<
			nameOrPhoneNumber << " in the list. Try again. " << std::endl;
	}
	else if (phone_number_format(nameOrPhoneNumber))
	{
		if (contacts.empty())
		{
			std::cout << "The contact list is empty. " << std::endl;
			return;
		}

		for (int i = 0; i < contacts.size(); ++i)
		{
			if (contacts[i].getPhoneNumber() == nameOrPhoneNumber)
			{
				std::cout << "The call was made to the contact: " <<
					"\nName: " << contacts[i].getName() <<
					"\nPhone number: " << contacts[i].getPhoneNumber() << std::endl;
				return;
			}
		}

		std::cerr << "Error! A contact with such a phone number \"" <<
			nameOrPhoneNumber << "\" is not in the list. " << std::endl;
	}
}

std::string Phone::add(const std::string& name, const std::string& phoneNumber)
{
	system("cls");
	if (!name_format(name))
	{
		std::cerr << "Error! Incorrect input name. Try again. " << std::endl;
		return "Error! ";
	}
	if (!phone_number_format(phoneNumber))
	{
		std::cerr << "Error! Incorrect input name. Try again. " << std::endl;
		return "Error! ";
	}
	Contact contact;
	contact.setName(name);
	contact.setPhoneNumber(phoneNumber);
	contacts.push_back(contact);
	std::cout << "\nThe contact: " << "\nName: " << name <<
		"\nPhone number: " << phoneNumber << "\nadded to contact list. " << std::endl;
	return "add";
}