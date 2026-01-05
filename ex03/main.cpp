#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TEST 1: Basic test from subject ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* me = new Character("me");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");
        
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }

    std::cout << "\n=== TEST 2: Full inventory (4 slots) ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* hero = new Character("hero");
        
        std::cout << "Equipping 4 materias:" << std::endl;
        hero->equip(src->createMateria("ice"));
        hero->equip(src->createMateria("cure"));
        hero->equip(src->createMateria("ice"));
        hero->equip(src->createMateria("cure"));
        
        std::cout << "\nTrying to equip 5th materia (should be ignored):" << std::endl;
        AMateria* extra = src->createMateria("ice");
        hero->equip(extra);
        delete extra; // Must delete manually since it wasn't equipped
        
        ICharacter* enemy = new Character("enemy");
        
        std::cout << "\nUsing all 4 slots:" << std::endl;
        hero->use(0, *enemy);
        hero->use(1, *enemy);
        hero->use(2, *enemy);
        hero->use(3, *enemy);
        
        delete enemy;
        delete hero;
        delete src;
    }

    std::cout << "\n=== TEST 3: Unequip and manual deletion ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        
        ICharacter* mage = new Character("mage");
        
        AMateria* ice = src->createMateria("ice");
        mage->equip(ice);
        
        std::cout << "Using equipped materia:" << std::endl;
        ICharacter* target = new Character("target");
        mage->use(0, *target);
        
        std::cout << "\nUnequipping materia (saving pointer):" << std::endl;
        AMateria* unequipped = ice; // Save pointer before unequip
        mage->unequip(0);
        
        std::cout << "Trying to use unequipped slot (should do nothing):" << std::endl;
        mage->use(0, *target);
        
        std::cout << "\nManually deleting unequipped materia:" << std::endl;
        delete unequipped;
        
        delete target;
        delete mage;
        delete src;
    }

    std::cout << "\n=== TEST 4: Deep copy of Character ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        Character* original = new Character("original");
        original->equip(src->createMateria("ice"));
        original->equip(src->createMateria("cure"));
        
        std::cout << "Creating deep copy:" << std::endl;
        Character* copy = new Character(*original);
        
        ICharacter* dummy = new Character("dummy");
        
        std::cout << "\nOriginal using materias:" << std::endl;
        original->use(0, *dummy);
        original->use(1, *dummy);
        
        std::cout << "\nCopy using materias (independent):" << std::endl;
        copy->use(0, *dummy);
        copy->use(1, *dummy);
        
        std::cout << "\nDeleting original (copy should still work):" << std::endl;
        delete original;
        
        std::cout << "Copy still working:" << std::endl;
        copy->use(0, *dummy);
        
        delete copy;
        delete dummy;
        delete src;
    }

    std::cout << "\n=== TEST 5: Assignment operator ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        Character char1("char1");
        char1.equip(src->createMateria("ice"));
        
        Character char2("char2");
        char2.equip(src->createMateria("cure"));
        
        ICharacter* target = new Character("target");
        
        std::cout << "Before assignment:" << std::endl;
        std::cout << "char1: ";
        char1.use(0, *target);
        std::cout << "char2: ";
        char2.use(0, *target);
        
        std::cout << "\nAssigning char1 to char2:" << std::endl;
        char2 = char1;
        
        std::cout << "\nAfter assignment (both should use ice):" << std::endl;
        std::cout << "char1: ";
        char1.use(0, *target);
        std::cout << "char2: ";
        char2.use(0, *target);
        
        delete target;
        delete src;
    }

    std::cout << "\n=== TEST 6: Unknown materia type ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        
        AMateria* unknown = src->createMateria("fire");
        if (unknown == NULL)
            std::cout << "Unknown materia type returned NULL (correct!)" << std::endl;
        else {
            std::cout << "ERROR: Unknown type should return NULL!" << std::endl;
            delete unknown;
        }
        
        delete src;
    }

    std::cout << "\n=== TEST 7: Invalid use/unequip indices ===" << std::endl;
    {
        ICharacter* hero = new Character("hero");
        ICharacter* target = new Character("target");
        
        std::cout << "Using invalid indices (should do nothing):" << std::endl;
        hero->use(-1, *target);
        hero->use(4, *target);
        hero->use(10, *target);
        
        std::cout << "Unequipping invalid indices (should do nothing):" << std::endl;
        hero->unequip(-1);
        hero->unequip(4);
        
        delete target;
        delete hero;
    }

    std::cout << "\n=== TEST 8: MateriaSource with 4 learned materias ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        
        std::cout << "Learning 4 materias:" << std::endl;
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        std::cout << "Trying to learn 5th (should be ignored):" << std::endl;
        AMateria* extra = new Ice();
        src->learnMateria(extra);
        delete extra; // Must delete manually since it wasn't learned
        
        std::cout << "Creating materias from learned templates:" << std::endl;
        AMateria* m1 = src->createMateria("ice");
        AMateria* m2 = src->createMateria("cure");
        
        delete m1;
        delete m2;
        delete src;
    }

    std::cout << "\n=== All tests completed successfully ===" << std::endl;
    std::cout << "Run with valgrind to verify no memory leaks!" << std::endl;
    
    return 0;
}