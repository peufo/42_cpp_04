#include "Cure.hpp"

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure& src): AMateria(src)
{
	std::cout << "Cure copy constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& src)
{
	if(this == &src)
		return *this;
	// TODO: It is Stupid ?
	this->type = src.type;
	std::cout << "Cure assignement constructor" << std::endl;
	return *this;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
