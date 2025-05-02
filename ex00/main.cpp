#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testAnimal()
{
	Animal a;
	Animal b(a);
	Animal c;

	a.makeSound();
	b.makeSound();
	c.makeSound();
	c = a;
	c.makeSound();
}

void testCat()
{
	Cat a;
	Cat b(a);
	Cat c;

	a.makeSound();
	b.makeSound();
	c.makeSound();
	c = a;
	c.makeSound();
}

void testDog()
{
	Dog a;
	Dog b(a);
	Dog c;

	a.makeSound();
	b.makeSound();
	c.makeSound();
	c = a;
	c.makeSound();
}

void test()
{
	const Animal* a = new Animal();
	const Animal* b = new Dog();
	const Animal* c = new Cat();

	std::cout << "Type animal: " <<  a->getType() << std::endl;
	std::cout << "Type dog: " <<  b->getType() << std::endl;
	std::cout << "Type cat: " <<  c->getType() << std::endl;
	a->makeSound();
	b->makeSound();
	c->makeSound();

	delete a;
	delete b;
	delete c;
}

void wrongTest()
{
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();

	std::cout << "Type animal: " <<  a->getType() << std::endl;
	std::cout << "Type cat: " <<  b->getType() << std::endl;
	a->makeSound();
	b->makeSound();

	delete a;
	delete b;
}

int main()
{
	test();
	// wrongTest();
	// testAnimal();
	// testDog();
	// testCat();

	return (0);
}
