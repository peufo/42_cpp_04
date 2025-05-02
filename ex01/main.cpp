#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testA()
{
	static const int nb = 4;
	Animal *animals[nb] = {0};

	for (int i = 0; i < nb; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < nb; i++)
		animals[i]->makeSound();

	for (int i = 0; i < nb; i++)
	{
		delete animals[i];
		animals[i] = 0;
	}
}

void testB()
{
	static const int nb = 4;
	Animal *animals[nb] = {0};
	Cat		cat;
	Dog		*dog = new Dog;

	for (int i = 0; i < nb; i++)
	{
		if (i % 2)
			animals[i] = new Cat(cat);
		else
			animals[i] = new Dog(*dog);
	}

	for (int i = 0; i < nb; i++)
		animals[i]->makeSound();

	for (int i = 0; i < nb; i++)
	{
		delete animals[i];
		animals[i] = 0;
	}

	delete dog;
	dog = 0;
}

int main()
{
	// testA();
	testB();

	return (0);
}
