#pragma once
#include <string>
#include <vector>
#include <iostream>

class Phone
{
private:
	class Contact
	{
	public:
		std::string name;
		std::string phoneNumber;
	};
	std::vector<Contact> contacts;
public:
	std::string add(const std::string& name, const std::string& phoneNumber);
	void call(const std::string& nameOrPhoneNumber);
	void send_message(const std::string& nameOrPhoneNumber);
	bool phone_number_format(const std::string& phoneNumber);
	bool name_format(const std::string& name);
};