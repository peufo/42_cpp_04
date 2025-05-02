#include "Brain.hpp"

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

void Brain::copyIdeas(const Brain& src)
{
	for (int i = 0; i < this->nbIdeas; i++)
		this->ideas[i] = src.ideas[i];
}

Brain::Brain(const Brain& src)
{
	this->copyIdeas(src);
	std::cout << "Brain copy constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
	if(this == &src)
		return *this;
	this->copyIdeas(src);
	std::cout << "Brain assignement constructor" << std::endl;
	return *this;
}
