#include "Cowboy.hpp"


namespace ariel{

    Cowboy::Cowboy(string name, Point point){}
    Cowboy::Cowboy(string name, Point point,int hp):Character(name,point,110){}

    bool Cowboy::hasboolets(){
        if(this->getBull() > 0){
            return true;
        }
        return false;
    }

    void Cowboy::reload(){
        if(!isAlive()){
            throw std::runtime_error("The Character is not alive");
        }
        else{
            this->bull=6;
        }
    }

    void Cowboy::shoot(Character* c ){
        if(c == nullptr){
            throw std::runtime_error("The Character is null");
        }
        else if(!isAlive() || !c->isAlive()){
            throw std::runtime_error("The Character is not alive");
        }
        else if(this == c){ 
            throw std::runtime_error("Can't attack yourself");
        }
        else if(hasboolets()){
            c->hit(10);
            bull--;
        }
        else{
            reload();
        }
    }

    string Cowboy::print(){
        if (!isAlive()) {
            return "Character Type : C\nCharacter Name : (" + this->getName() + ")\nCharacter Location : " + this->getLocation().print();
        } else {
            return "Character Type : C\nCharacter Name : " + this->getName() + "\nCharacter Location : " + this->getLocation().print()
            + "\nCharacter HP : " + to_string(this->getLifeSpan()) + "\nCharacter Bullets : " + to_string(getBull());
        }
    }

    void Cowboy::attack(Character* enemy){
        this->shoot(enemy);
    }
}