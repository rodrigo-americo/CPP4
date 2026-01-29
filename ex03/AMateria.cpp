#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria & src) : type(src.type) {}

AMateria::~AMateria() {}

AMateria & AMateria::operator=(const AMateria &) { std::cout << " Function disabled " << std::endl; return *this;}

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter&) { std::cout << "* does nothing *" << std::endl; }
