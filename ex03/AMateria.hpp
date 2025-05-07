#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class ICharacter;
class MateriaSource;

class AMateria
{
	protected:
		const std::string type;
		MateriaSource* source;
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
		void setOwner(const ICharacter* owner);
		void setSource(MateriaSource* source);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
