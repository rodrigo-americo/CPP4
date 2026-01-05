#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const std::string &type);
        Dog(const Dog &src);
        ~Dog();

        Dog &operator=(const Dog &src);

        void makeSound() const;
};
#endif
