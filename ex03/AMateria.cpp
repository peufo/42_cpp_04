#include "AMateria.hpp"

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

AMateria::AMateria(): type("undefined materia"), source(0), owner(0)
{
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(const std::string & type): type(type), source(0), owner(0)
{
	std::cout << "AMateria constructor (type=" << type << ")" << std::endl;
}

AMateria::AMateria(const AMateria& src): type(src.type), source(src.source), owner(src.owner)
{
	std::cout << "AMateria copy constructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& src)
{
	if(this == &src)
		return *this;
	this->owner = src.owner;
	this->source = src.source;
	if (this->source && !this->owner)
		this->source->addMateriaOnFloor(this);
	std::cout << "AMateria assignement constructor" << std::endl;
	return *this;
}

const std::string& AMateria::getType() const
{
	return this->type;
}

void AMateria::leaveOnFloor()
{
	if (!this->source)
	{
		std::cout << "You cannot leave this materia on the floor, because materia's source is not defined !" << std::endl;
		return ;
	}
	this->source->addMateriaOnFloor(this);
}

AMateria* AMateria::takeBy(const ICharacter* owner)
{
	this->owner = owner;
	if (this->source)
		this->source->removeMateriaFromFloor(this);
	return this;
}

const ICharacter* AMateria::getOwner() const
{
	return this->owner;
}

void AMateria::setOwner(const ICharacter* owner)
{
	this->owner = owner;
}

void AMateria::setSource(MateriaSource* source)
{
	this->source = source;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Use a materia on " << target.getName() << std::endl;
}
