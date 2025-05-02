#include "MateriaSource.hpp"

void MateriaSource::initMaterias()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	for (int i = 0; i < 100; i++)
		this->floor[i] = 0;
}

AMateria* MateriaSource::addMateriaOnFloor(const AMateria * src)
{
	for (int i = 0; i < 100; i++)
	{
		if (!this->floor[i])
		{
			this->floor[i] = src->clone();
			this->floor[i]->leaveOnFloor();
			return this->floor[i];
		}
	}
	std::cout << "Cannot add more materia" << std::endl;
	return 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = 0;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->floor[i] && !this->floor[i]->getOwner())
		{
			delete this->floor[i];
			this->floor[i] = 0;
		}
	}
	std::cout << "MateriaSource destructor" << std::endl;
}

MateriaSource::MateriaSource()
{
	this->initMaterias();
	std::cout << "MateriaSource default contructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	this->initMaterias();
	for (int i = 0; i < 4; i++)
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if(this == &src)
		return *this;
	this->initMaterias();
	for (int i = 0; i < 4; i++)
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = materia;
			return ;
		}
	}
	std::cout << "MateriaSource can't learn more than 4 materia !" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return this->addMateriaOnFloor(this->inventory[i]);
	return 0;
}
