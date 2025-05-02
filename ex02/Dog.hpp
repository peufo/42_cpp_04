#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		virtual ~Dog();
		Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog& src);
		virtual void makeSound() const;
};

#endif
