#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "=== EX01: Array of Animals (from exercise) ===" << std::endl;
    {
        // Create and fill array - half Dogs, half Cats
        const int size = 10;
        Animal* animals[size];
        
        std::cout << "\nCreating array of " << size << " animals:" << std::endl;
        for (int i = 0; i < size; i++) {
            if (i < size / 2) {
                std::cout << "\nCreating Dog " << i << ":" << std::endl;
                animals[i] = new Dog();
            } else {
                std::cout << "\nCreating Cat " << i << ":" << std::endl;
                animals[i] = new Cat();
            }
        }
        
        std::cout << "\n=== All animals making sounds ===" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << i << ". " << animals[i]->getType() << ": ";
            animals[i]->makeSound();
        }
        
        // Delete each Animal (must call proper destructors!)
        std::cout << "\n=== Deleting all animals ===" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << "\nDeleting animal " << i << ":" << std::endl;
            delete animals[i];
        }
    }

    std::cout << "\n=== Testing Deep Copy (required by exercise) ===" << std::endl;
    {
        std::cout << "\n--- Dog deep copy test ---" << std::endl;
        Dog original;
        std::cout << "\nCreating copy:" << std::endl;
        Dog copy(original);
        
        std::cout << "\nBoth dogs exist independently" << std::endl;
        std::cout << "Destroying (each should delete its own Brain):" << std::endl;
    }
    
    {
        std::cout << "\n--- Cat deep copy test ---" << std::endl;
        Cat cat1;
        std::cout << "\nCreating cat2 as copy:" << std::endl;
        Cat cat2(cat1);
        
        std::cout << "\nAssignment operator test:" << std::endl;
        Cat cat3;
        cat3 = cat1;
        
        std::cout << "\nAll 3 cats exist independently" << std::endl;
        std::cout << "Destroying (each should delete its own Brain):" << std::endl;
    }

    std::cout << "\n=== Additional test: Deleting through Animal* ===" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << "\nDeleting Dog through Animal*:" << std::endl;
        delete j; // Must not create a leak!
        
        std::cout << "\nDeleting Cat through Animal*:" << std::endl;
        delete i; // Must not create a leak!
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    std::cout << "Run with valgrind to verify no memory leaks!" << std::endl;
    return 0;
}
