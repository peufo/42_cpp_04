#include "Cat.hpp"

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete this->brain;
	this->brain = 0;
}

Cat::Cat(): Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& src): Animal(src)
{
	this->brain = new Brain();
	std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	if(this == &src)
	return *this;
	this->type = src.type;
	this->brain = new Brain();
	std::cout << "Cat assignement constructor" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaaaaaouh" << std::endl;
}
