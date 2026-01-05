#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &src);
        ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &src);

        void makeSound() const;
        std::string getType() const;
};
#endif
