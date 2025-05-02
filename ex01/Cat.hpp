#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;
	public:
		virtual ~Cat();
		Cat();
		Cat(const Cat& src);
		Cat& operator=(const Cat& src);
		virtual void makeSound() const;
};

#endif
