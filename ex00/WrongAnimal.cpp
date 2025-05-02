#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	this->type = "";
	std::cout << "WrongAnimal default contructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & src)
{
	this->type = src.type;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	std::cout << "WrongAnimal assignement constructor" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "?????" << std::endl;
}
