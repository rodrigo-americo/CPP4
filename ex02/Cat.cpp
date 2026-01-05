#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    std::cout << "Cat constructor called" << std::endl;
}
Cat::Cat(const std::string &type) : Animal(type), brain(new Brain())
{
    std::cout << "Cat constructor " << type << " called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src), brain(new Brain())
{
    std::cout << "Cat constructor copy called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
    {
        Animal::operator=(src);
        *brain = *src.brain;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "MIAUUU..." << std::endl;
}