#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource & src) {
    for (int i = 0; i < 4; i++)
    {
        if (src.inventory[i] == NULL)
        {
            inventory[i] = NULL;
            continue;
        }
        inventory[i] = src.inventory[i]->clone();
    }
}

MateriaSource & MateriaSource::operator=(const MateriaSource & src) {
    if (this == &src)
    {
        return *this;
    }
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        if (src.inventory[i] == NULL)
        {
            inventory[i] = NULL;
            continue;
        }
        inventory[i] = src.inventory[i]->clone();
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            continue;
        }
        if (inventory[i]->getType() == type)
        {
            return inventory[i]->clone();
        }
    }
    return NULL;
}
