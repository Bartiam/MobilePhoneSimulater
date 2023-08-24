#pragma once
#include <string>
#include <vector>
#include <iostream>

class Contact
{
private:
	std::string name;
	std::string phoneNumber;

public:
	std::string getName();
	std::string getPhoneNumber();
	void setName(const std::string& name);
	void setPhoneNumber(const std::string& phoneNumber);
};

class Phone
{
private:
	std::vector<Contact> contacts;
public:
	std::string add(const std::string& name, const std::string& phoneNumber);
	void call(const std::string& nameOrPhoneNumber);
	void send_message(const std::string& nameOrPhoneNumber);
	bool phone_number_format(const std::string& phoneNumber);
	bool name_format(const std::string& name);
};