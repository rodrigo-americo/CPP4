#include "Brain.hpp"
#include <iostream>
#include <string>
#include <sstream>

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        std::stringstream ss;
        ss << "Default idea " << i;
        ideas[i] = ss.str();
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{   
    for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
    std::cout << "Brain constructor copy called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    if (this != &src)
        for (int i = 0; i < 100; i++)
            ideas[i] = src.ideas[i];
    return *this;
}
