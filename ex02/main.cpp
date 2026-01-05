#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "=== EX02: Abstract Class Test ===" << std::endl;
    
    // This should NOT compile - Animal is abstract!
    // const Animal* meta = new Animal();  // ❌ Error!
    
    std::cout << "\n=== Creating Dogs and Cats (should work) ===" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << "\nTypes:" << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        
        std::cout << "\nSounds:" << std::endl;
        i->makeSound(); // Will print cat sound!
        j->makeSound(); // Will print dog sound!
        
        std::cout << "\nDeleting (check for memory leaks):" << std::endl;
        delete j; // Should not create a leak
        delete i; // Should not create a leak
    }

    std::cout << "\n=== Array of Animals Test ===" << std::endl;
    {
        const int size = 6;
        Animal* animals[size];
        
        std::cout << "Creating array:" << std::endl;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        
        std::cout << "\nAll animals making sounds:" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << animals[i]->getType() << ": ";
            animals[i]->makeSound();
        }
        
        std::cout << "\nDeleting all:" << std::endl;
        for (int i = 0; i < size; i++) {
            delete animals[i];
        }
    }

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    {
        Dog dog1;
        std::cout << "\nCreating copy:" << std::endl;
        Dog dog2(dog1);
        
        std::cout << "\nBoth dogs making sounds:" << std::endl;
        dog1.makeSound();
        dog2.makeSound();
        
        std::cout << "\nDestruction:" << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    std::cout << "Note: Animal cannot be instantiated directly!" << std::endl;
    std::cout << "Run with valgrind to verify no memory leaks." << std::endl;
    
    return 0;
}