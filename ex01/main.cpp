#include "main.h"

std::string get_input(std::string msg)
{
	std::string res = "";

	std::cout << msg;
	std::getline(std::cin, res);
	if (!is_print(res))
	{
		std::cout << "Warning: non-printable character!" << std::endl;
		res = get_input(msg);
	}
	else if (res.compare("") == 0)
		res = get_input(msg);
	return (res);
}

bool	is_print(std::string s)
{
	size_t	i = 0;

	while (i++ < s.length())
		if ((s[i - 1] < 31 || s[i - 1] > 127) && (!isspace(s[i - 1])))
			return false;
	return true;
}

void	add_all(Phonebook *phonebook)
{
	int	i = 0;
	
	while (++i < 9)
	{
		std::stringstream ss;
		ss << i;
		std::string str = ss.str();
		Contact contact(str, str, str, str, str);
		phonebook->add(contact);
	}
	std::cout << "8 contacts were added successfuly" << std::endl;
}

void	add_contact(Phonebook *phonebook)
{
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string number;
	std::string dark;

	f_name = get_input("Enter first name: ");
	l_name = get_input("Enter last name: ");
	n_name = get_input("Enter nickname: ");
	number = get_input("Enter phone number: ");
	dark = get_input("Enter dark secret: ");
	Contact contact(f_name, l_name, n_name, number, dark);
	phonebook->add(contact);
}

void	search(Phonebook phonebook)
{
	int			idx;
	std::string	inp;

	phonebook.print_all();
	while (true)
	{
		inp = get_input("Select Contac (0 to exit): ");
		if (inp == "0")
			return;
		std::istringstream(inp) >> idx;
		if (idx)
			phonebook.print_one(idx - 1);
	}
}

void	run_cmd(Phonebook *phonebook)
{
	std::string	cmd;

	std::cout << "Enter Command: ";
	if (!std::getline(std::cin, cmd))
		return;
	if (cmd.compare("ADD") == 0)
		add_contact(phonebook);
	if (cmd.compare("SEARCH") == 0)
		search(*phonebook);
	if (cmd.compare("ADD8") == 0)
		add_all(phonebook);
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