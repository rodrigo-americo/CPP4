#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}
Cat::Cat(const std::string &type) : Animal(type)
{
    std::cout << "Cat constructor " << type << " called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat constructor copy called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
    {
        Animal::operator=(src);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MIAUUU..." << std::endl;
}