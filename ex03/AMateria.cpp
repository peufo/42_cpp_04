#include "AMateria.hpp"

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

AMateria::AMateria()
{
	this->type = "undefined materia";
	this->owner = 0;
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(const std::string & type)
{
	this->type = type;
	this->owner = 0;
	std::cout << "AMateria constructor (type=" << type << ")" << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
	this->type = src.type;
	this->owner = src.owner;
	std::cout << "AMateria copy constructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& src)
{
	if(this == &src)
		return *this;
	this->type = src.type;
	this->owner = src.owner;
	std::cout << "AMateria assignement constructor" << std::endl;
	return *this;
}

const std::string& AMateria::getType() const
{
	return this->type;
}

void AMateria::leaveOnFloor()
{
	this->owner = 0;
}

AMateria* AMateria::takeBy(const ICharacter* owner)
{
	this->owner = owner;
	return this;
}

const ICharacter* AMateria::getOwner() const
{
	return this->owner;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Use a materia on " << target.getName() << std::endl;
}
