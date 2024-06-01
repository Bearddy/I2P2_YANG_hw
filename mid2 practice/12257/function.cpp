#include "function.h"

using namespace std;

Animal::Animal(Zoo *zoo, string name){
    this->belong = zoo;
    this->species = name;
    this->belong->born(name);
}

Dog::Dog(Zoo *zoo) : Animal(zoo, "Dog") {
    this->legs = 4;
}

Dog::~Dog(){

}

Cat::Cat(Zoo *zoo) : Animal(zoo, "Cat") {
    this->legs = 4;
}

Cat::~Cat(){
    
}

Caog::Caog(Zoo *zoo) : Animal(zoo, "Caog"), Dog(zoo), Cat(zoo) {
    this->legs = 4;
}

Caog::~Caog(){

}

void Caog::barking(){
    cout << "woof!woof!meow!\n";
}

void Caog::carton(){
    cout << "it looks so happy!\n";
}

void Caog::throwBall(){
    cout << "it looks happy!\n";
}