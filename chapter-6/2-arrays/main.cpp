#include <iostream>
#include <string>

// Question 1 is just declaring this bad boy.
double highTemps[365]{};

namespace constant {
enum class animal {
    CHICKEN,
    DOG,
    CAT,
    ELEPHANT,
    DUCK,
    SNAKE,
};
}

int numLegs[6]{2, 4, 4, 4, 2, 0};

std::string getAnimalName(constant::animal animal) {
    switch (static_cast<int>(animal)) {
        case static_cast<int>(constant::animal::CHICKEN):
            return "Chicken";
        case static_cast<int>(constant::animal::DOG):
            return "Dog";
        case static_cast<int>(constant::animal::CAT):
            return "Cat";
        case static_cast<int>(constant::animal::ELEPHANT):
            return "Elephant";
        case static_cast<int>(constant::animal::DUCK):
            return "Duck";
        case static_cast<int>(constant::animal::SNAKE):
            return "Snake";
        default:
            return "???";
    }
}

void printAnimalLegs(constant::animal animal) {
    std::cout << "The " << getAnimalName(animal) << " has "
              << numLegs[static_cast<int>(animal)] << " legs." << '\n';
}

int main() { printAnimalLegs(constant::animal::ELEPHANT); }
