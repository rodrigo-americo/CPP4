#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog constructor copy called" << std::endl;
    *this = src;
}

Dog::Dog(const std::string &type) : Animal(type)
{
    std::cout << "Dog constructor " << type << " called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
    {
        type = src.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Au au au..." << std::endl;
}
