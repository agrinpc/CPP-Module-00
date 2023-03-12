#include "./Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string f_name, std::string l_name, std::string number, std::string dark)
{
	this->f_name = f_name;
	this->l_name = l_name;
	this->number = number;
	this->dark = dark;
}

Contact::~Contact() {}

std::string Contact::get_fname()
{
	return this->f_name;
}

std::string Contact::get_lname()
{
	return this->l_name;
}

std::string Contact::get_number()
{
	return this->number;
}

std::string Contact::get_dark()
{
	return this->dark;
}