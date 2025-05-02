#include "WrongCat.hpp"

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(): WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	if(this == &src)
		return *this;
	this->type = src.type;
	std::cout << "WrongCat assignement constructor" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaaaaaouh" << std::endl;
}
