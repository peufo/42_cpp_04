#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void test1() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void test2() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* a = src->createMateria("ice");
	AMateria* b = src->createMateria("cure");
	AMateria* c = src->createMateria("unknown");

	me->equip(a);
	me->equip(b);
	me->equip(c);
	me->equip(a);
	me->equip(b);
	me->equip(c);
	me->equip(a);
	me->equip(b);
	me->equip(c);

	me->use(-1, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(42, *bob);

	me->unequip(-1);
	me->unequip(0);
	me->unequip(2);
	me->unequip(4);
	me->equip(src->createMateria("unknown"));
	me->equip(src->createMateria("ice"));

	me->use(-1, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(42, *bob);

	me->unequip(1);

	delete bob;
	delete me;
	delete src;
}

void test3()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	for (int i = 0; i < 60; i++)
	{
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
	}

	delete src;
	delete me;
}

int main()
{
	test1();
	test2();
	test3();

	return 0;
}
