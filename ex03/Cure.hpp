#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		~Cure();
		Cure();
		Cure(const Cure& src);
		Cure& operator=(const Cure& src);
		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif
