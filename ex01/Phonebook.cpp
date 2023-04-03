#include "./Phonebook.hpp"

Phonebook::Phonebook(void) : size(0), cur(0) {return;}


Phonebook::~Phonebook() {}

void	Phonebook::add(Contact cont)
{
	this->contacts[this->cur % 8] = cont;
	this->cur++;
	if (this->size < 8)
		this->size++;
	return;
}

int	Phonebook::get_size()
{
	return (this->size);
}

Contact *Phonebook::get_contacts()
{
	return (this->contacts);
}

void	Phonebook::print_all()
{
	int	i;
	int c = 0;

	i = this->cur % 8 - 1;
	while (++i < size && ++c)
	{
		std::cout << c << "|";
		std::cout << format_text(this->contacts[i].get_fname()) <<  "|";
		std::cout << format_text(this->contacts[i].get_lname()) << "|";
		std::cout << format_text(this->contacts[i].get_nname()) << std::endl;
	}
	i = -1;
	while (++i < this->cur % 8 && ++c)
	{
		std::cout << c << "|";
		std::cout << format_text(this->contacts[i].get_fname()) <<  "|";
		std::cout << format_text(this->contacts[i].get_lname()) << "|";
		std::cout << format_text(this->contacts[i].get_nname()) << std::endl;
	}
	return;
}

void	Phonebook::print_one(int idx)
{
	if (idx < this->size)
	{
		std::cout << "cur : " << this->cur << " size: " << this->size << " idx:" << idx << std::endl;
		if (this->cur > this->size)
		{
			if (idx < this->size - this->cur % 8)
				idx += this->cur % 8;
			else
				idx = this->size - (this->cur % 8) - idx;
		}
		std::cout << "First Name:  " << this->contacts[idx].get_fname() << std::endl;
		std::cout << "Last Name:   " << this->contacts[idx].get_lname() << std::endl;
		std::cout << "Nickname:   " << this->contacts[idx].get_nname() << std::endl;
		std::cout << "Number:      " << this->contacts[idx].get_number() << std::endl;
		std::cout << "Dark Secret: " << this->contacts[idx].get_dark() << std::endl;
	}
	else
		std::cout << "Index is not valid!" << std::endl;
}

std::string	format_text(std::string s)
{
	s = "          " + s;
	return (s.length() > 20 ? s.substr(10, 9) + "." : s.substr(s.length() - 10, 10));
}