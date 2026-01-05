#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type()
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
    std::cout << "Animal constructor " << type << " called" << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type)
{
    std::cout << "Animal constructor copy called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src){
    if (this != &src)
        type = src.type;
    return *this;
}

void Animal::makeSound() const{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const{
    return type;
}
