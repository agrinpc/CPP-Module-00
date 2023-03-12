#include "main.h"

std::string get_input(std::string msg)
{
	std::string res = "";

	std::cout << msg;
	std::getline(std::cin, res);
	if (res.compare("") == 0)
		res = get_input(msg);
	return (res);
}

void	add_contact(Phonebook *phonebook)
{
	std::string f_name;
	std::string l_name;
	std::string number;
	std::string dark;
	Contact contact;

	f_name = get_input("Enter first name: ");
	l_name = get_input("Enter last name: ");
	number = get_input("Enter phone number: ");
	dark = get_input("Enter dark secret: ");
	contact = Contact(f_name, l_name, number, dark);
	phonebook->add(contact);
}

void	search(Phonebook phonebook)
{
	int	size;
	int	i = -1;
	Contact *contacts;

	size = phonebook.get_size();
	contacts = phonebook.get_contacts();
	while (++i < size)
		std::cout << i + 1 << " - " << contacts[i].get_fname() <<  " " << contacts[i].get_lname() << " " << contacts[i].get_number() << " " << contacts[i].get_dark() << std::endl;
}

void	run_cmd(Phonebook *phonebook)
{
	std::string	cmd;

	std::cout << "Enter Command: ";
	std::getline(std::cin, cmd);
	if (cmd.compare("ADD") == 0)
		add_contact(phonebook);
	if (cmd.compare("SEARCH") == 0)
		search(*phonebook);
	if (cmd.compare("EXIT") == 0)
		return ;
	run_cmd(phonebook);
}

int	main(void)
{
	Phonebook phonebook = Phonebook();

	run_cmd(&phonebook);
	return (0);
}