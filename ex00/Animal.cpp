#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal::Animal()
{
	this->type = "";
	std::cout << "Animal default contructor" << std::endl;
}

Animal::Animal(const Animal & src)
{
	this->type = src.type;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	std::cout << "Animal assignement constructor" << std::endl;
	return (*this);
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "?????" << std::endl;
}
