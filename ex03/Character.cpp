#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("") 
{
	for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}

Character::Character(const Character & src) : name(src.name)
{
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

Character & Character::operator=(const Character & src)
{
    if (this == &src)
    {
        return *this;
    }
    name = src.name;
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

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
    }
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}

AMateria* Character::getMateria(int idx) const {
    if (idx >= 0 && idx < 4)
        return inventory[idx];
    return NULL;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        return;
    }
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        return;
    }
    if (inventory[idx] == NULL)
    {
        return;
    }
    inventory[idx]->use(target);
}

std::string const & Character::getName() const {
    return name;
}
