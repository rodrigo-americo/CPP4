#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type()
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
    std::cout << "WrongAnimal constructor " << type << " called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
    std::cout << "WrongAnimal constructor copy called" << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src){
    if (this != &src)
        type = src.type;
    return *this;
}

void WrongAnimal::makeSound() const{
    std::cout << "Animal sound" << std::endl;
}


std::string WrongAnimal::getType() const{
    return type;
}