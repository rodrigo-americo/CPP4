#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src){
    std::cout << "WrongCat constructor copy called" << std::endl;
    *this = src;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src){
    if (this != &src)
        type = src.type;
    return *this;
}

void WrongCat::makeSound() const{
    std::cout << "Meow meow meow..." << std::endl;
}
