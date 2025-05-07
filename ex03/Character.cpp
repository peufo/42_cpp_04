#include "Character.hpp"

void Character::initSlots()
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = 0;
}

void Character::copyMaterias(const Character & src)
{
	for (int i = 0; i < 4; i++)
	{
		this->slots[i] = 0;
		if (src.slots[i])
			this->slots[i] = src.slots[i]->clone();
	}
}

bool Character::isValidSlot(int index)
{
	if (index < 0 || index > 3)
	{
		this->say() << "Invalid slot [" << index << "]" << std::endl;
		return false;
	}
	return true;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i])
		{
			delete this->slots[i];
			this->slots[i] = 0;
		}
	}
	std::cout << "Character destructor" << std::endl;
}

Character::Character(): name("Unknown")
{
	this->initSlots();
	std::cout << "Character default constructor" << std::endl;
}

Character::Character(const std::string& name): name(name)
{
	this->initSlots();
	std::cout << "Character constructor (name=" << this->name << ")" << std::endl;
}

Character::Character(const Character& src)
{
	this->name = src.name;
	this->copyMaterias(src);
	std::cout << "Character copy constructor" << std::endl;
}

Character& Character::operator=(const Character& src)
{
	if(this == &src)
		return *this;
	this->name = src.name;
	this->copyMaterias(src);
	std::cout << "Character assignement constructor" << std::endl;
	return *this;
}

const std::string& Character::getName() const
{
	return this->name;
}

std::ostream& Character::say() const
{
	return std::cout << this->name << ":\t";
}

void Character::equip(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] == materia)
		{
			this->say() << "I'm already equiped with this materia... How it's possible ?" << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->slots[i])
		{
			this->slots[i] = materia->takeBy(this);
			this->say() << "New materia " << materia->getType() <<" equiped in slot [" << i << "]" << std::endl;
			return ;
		}
	}
	this->say() << "No slot available to equip new materia, I leave it on the floor !" << std::endl;
	materia->leaveOnFloor();
}

void Character::unequip(int index)
{
	if (!this->isValidSlot(index))
		return ;
	if (!this->slots[index])
	{
		this->say() << "Slot [" << index << "] is already empty" << std::endl;
		return ;
	}
	this->slots[index]->leaveOnFloor();
	this->slots[index] = 0;
}

void Character::use(int index, ICharacter& target)
{
	if (!this->isValidSlot(index))
		return ;
	if (!this->slots[index])
	{
		this->say() << "Slot [" << index << "] is empty" << std::endl;
		return ;
	}
	this->slots[index]->use(target);
}
