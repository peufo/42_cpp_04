#include "Ice.hpp"

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice& src): AMateria(src)
{
	std::cout << "Ice copy constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& src)
{
	if(this == &src)
		return *this;
	// TODO: It is Stupid ?
	this->type = src.type;
	std::cout << "Ice assignement constructor" << std::endl;
	return *this;
}

Ice* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

