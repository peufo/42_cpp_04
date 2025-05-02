#include "Dog.hpp"

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete this->brain;
	this->brain = 0;
}

Dog::Dog(): Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& src): Animal(src)
{
	this->brain = new Brain();
	std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	if(this == &src)
		return *this;
	this->type = src.type;
	this->brain = new Brain();
	std::cout << "Dog assignement constructor" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Ouaf! Ouaf!" << std::endl;
}
