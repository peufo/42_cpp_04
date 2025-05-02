#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	protected:
		static const int nbIdeas = 100;
		std::string ideas[nbIdeas];
		void copyIdeas(const Brain& src);
	public:
		~Brain();
		Brain();
		Brain(const Brain& src);
		Brain& operator=(const Brain& src);
};

#endif
