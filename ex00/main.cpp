#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TEST 1: Basic polymorphism test (from exercise) ===" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << "\nTypes:" << std::endl;
        std::cout << "j type: " << j->getType() << std::endl;
        std::cout << "i type: " << i->getType() << std::endl;
        
        std::cout << "\nSounds:" << std::endl;
        i->makeSound(); // should print cat sound!
        j->makeSound(); // should print dog sound!
        meta->makeSound(); // should print generic animal sound
        
        std::cout << "\nDeleting (check for memory leaks):" << std::endl;
        delete meta;
        delete j;
        delete i;
    }

    std::cout << "\n=== TEST 2: Wrong classes (no polymorphism) ===" << std::endl;
    {
        const WrongAnimal* wrong = new WrongCat();
        
        std::cout << "\nType: " << wrong->getType() << std::endl;
        std::cout << "Sound: ";
        wrong->makeSound(); // should print WrongAnimal sound, NOT WrongCat!
        
        std::cout << "\nDeleting:" << std::endl;
        delete wrong;
    }

    std::cout << "\n=== TEST 3: Direct instantiation (not through pointers) ===" << std::endl;
    {
        Dog dog;
        Cat cat;
        
        std::cout << "\nDirect calls:" << std::endl;
        dog.makeSound();
        cat.makeSound();
        
        std::cout << "\nDestruction will happen automatically:" << std::endl;
    }

    std::cout << "\n=== TEST 4: Copy constructor test ===" << std::endl;
    {
        Dog original;
        std::cout << "\nCreating copy:" << std::endl;
        Dog copy(original);
        
        std::cout << "\nBoth making sounds:" << std::endl;
        original.makeSound();
        copy.makeSound();
        
        std::cout << "\nDestruction:" << std::endl;
    }

    std::cout << "\n=== TEST 5: Assignment operator test ===" << std::endl;
    {
        Cat cat1;
        Cat cat2;
        
        std::cout << "\nAssigning cat1 to cat2:" << std::endl;
        cat2 = cat1;
        
        std::cout << "\nBoth making sounds:" << std::endl;
        cat1.makeSound();
        cat2.makeSound();
        
        std::cout << "\nDestruction:" << std::endl;
    }

    std::cout << "\n=== TEST 6: Array of Animals (polymorphic behavior) ===" << std::endl;
    {
        const Animal* animals[4];
        
        std::cout << "Creating array:" << std::endl;
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();
        
        std::cout << "\nAll animals making sounds:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << animals[i]->getType() << ": ";
            animals[i]->makeSound();
        }
        
        std::cout << "\nDeleting all:" << std::endl;
        for (int i = 0; i < 4; i++) {
            delete animals[i];
        }
    }

    std::cout << "\n=== TEST 7: Comparing polymorphic vs non-polymorphic side by side ===" << std::endl;
    {
        std::cout << "WITH virtual (correct polymorphism):" << std::endl;
        const Animal* correctCat = new Cat();
        std::cout << "Type: " << correctCat->getType() << " | Sound: ";
        correctCat->makeSound();
        delete correctCat;
        
        std::cout << "\nWITHOUT virtual (broken polymorphism):" << std::endl;
        const WrongAnimal* wrongCat = new WrongCat();
        std::cout << "Type: " << wrongCat->getType() << " | Sound: ";
        wrongCat->makeSound();
        delete wrongCat;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}