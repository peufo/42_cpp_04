#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

#define FLOOR_SIZE 100

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *inventory[4];
		AMateria *floor[FLOOR_SIZE];
		void initMaterias();
	public:
		~MateriaSource();
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource& operator=(const MateriaSource& src);
		virtual void learnMateria(AMateria *materia);
		virtual AMateria* createMateria(std::string const & type);
		AMateria *addMateriaOnFloor(AMateria *src);
		void	removeMateriaFromFloor(const AMateria *src);
		bool	isMateriaOnFloor(const AMateria *src);
		bool	isFloorFull();
};

#endif
