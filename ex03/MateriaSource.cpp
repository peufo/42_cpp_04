#include "MateriaSource.hpp"

void MateriaSource::initMaterias()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	for (int i = 0; i < FLOOR_SIZE; i++)
		this->floor[i] = 0;
}

AMateria* MateriaSource::addMateriaOnFloor(AMateria* src)
{

	if (this->isMateriaOnFloor(src))
		return src;
	for (int i = 0; i < FLOOR_SIZE; i++)
	{
		if (!this->floor[i])
		{
			std::cout << "materia leaved on floor [" << i << "]" << std::endl;
			this->floor[i] = src;
			this->floor[i]->setOwner(0);
			return this->floor[i];
		}
	}
	std::cout << "Cannot add more materia on the floor" << std::endl;
	return 0;
}

void MateriaSource::removeMateriaFromFloor(const AMateria* src)
{
	for (int i = 0; i < FLOOR_SIZE; i++)
	{
		if (this->floor[i] && this->floor[i] == src)
		{
			std::cout << "Materia taked on floor [" << i << "]" << std::endl;
			this->floor[i] = 0;
			return ;
		}
	}
}

bool MateriaSource::isMateriaOnFloor(const AMateria* src)
{
	for (int i = 0; i < FLOOR_SIZE; i++)
	{
		if (this->floor[i] == src)
			return true;
	}
	return false;
}

bool MateriaSource::isFloorFull()
{
	for (int i = 0; i < FLOOR_SIZE; i++)
	{
		if (!this->floor[i])
			return false;
	}
    return true;
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
	for (int i = 0; i < FLOOR_SIZE; i++)
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
			this->inventory[i]->setSource(this);
			return ;
		}
	}
	std::cout << "MateriaSource can't learn more than 4 materia !" << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	if (this->isFloorFull())
	{
		std::cout << "Source can't create more materia... Sorry" << std::endl;
		return 0;
	}
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return this->addMateriaOnFloor(this->inventory[i]->clone());
	return 0;
}
