#include "./Phonebook.hpp"

Phonebook::Phonebook()
{
	this->size = 0;
}

Phonebook::~Phonebook() {}

void	Phonebook::add(Contact cont)
{
	this->contacts[this->size] = cont;
	this->size++;
}

int	Phonebook::get_size()
{
	return (this->size);
}

Contact *Phonebook::get_contacts()
{
	return (this->contacts);
}