#include <iostream>
#include <string>

class Animal
{
protected:
    std::string Animaltype;
public:
    virtual Animal* clone() = 0;

    std::string getAnimaltype()
    {
        return Animaltype;
    }
};
//sheep
class Sheep : public Animal
{
public:
    Sheep()
    {
        Animaltype = "Sheep is being made"; 
        std::cout << "sheep is made" << std::endl;
        std::cout << this << std::endl;

    }


    Animal* clone()
    {
        return new Sheep(*this);
    }
};

//factory
class ClonedFactory
{
    static Animal* sally;

public:
    static void  initialize()
    {
        sally = new Sheep();
    }

    static Animal* getTypeSheep()
    {
        return sally->clone();
    }
};

Animal* ClonedFactory::sally = 0;

int main()
{
    ClonedFactory::initialize();
    Animal* ClonedSheep;
    ClonedSheep = ClonedFactory::getTypeSheep();
    std::cout << ClonedSheep->getAnimaltype() << std::endl;
    std::cout << "cloned sheep address "<<&ClonedSheep << std::endl;
    return 0;
}