#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria* slots[4];
		void initSlots();
		void copyMaterias(const Character& src);
		bool isValidSlot(int index);
	public:
		~Character();
		Character();
		Character(const std::string& name);
		Character(const Character& src);
		Character& operator=(const Character& src);
		const std::string& getName() const;
		std::ostream& say() const;
		virtual void equip(AMateria* materia);
		virtual void unequip(int index);
		virtual void use(int index, ICharacter& target);
};

#endif
