#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
		const ICharacter* owner;
	public:
		virtual ~AMateria();
		AMateria();
		AMateria(const AMateria& src);
		AMateria(const std::string& type);
		AMateria& operator=(const AMateria& src);
		const std::string& getType() const;
		void leaveOnFloor();
		AMateria* takeBy(const ICharacter* owner);
		const ICharacter* getOwner() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
