#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *inventory[4];
		AMateria *floor[100];
		void initMaterias();
		AMateria *addMateriaOnFloor(const AMateria *src);
	public:
		~MateriaSource();
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource& operator=(const MateriaSource& src);
		virtual void learnMateria(AMateria *materia);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
