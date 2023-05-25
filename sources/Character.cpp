#include "Character.hpp"
using namespace std;

namespace ariel {

    Character::Character(string name,const Point& point) : name(name), point(point) {};
    Character::Character(string name,const Point& point, int _hp) : name(name), point(point),lifeSpan(_hp) {};
    Character::Character(){};

    bool Character::isAlive(){
        if(this->getLifeSpan() > 0){
            return true;
        }
        return false;
    }

    double Character::distance(Character* character){
        return this->distance(character);
    }

    void Character::hit(int hitNUm){
        if(hitNUm < 0){
            throw invalid_argument("Can't be a negative input");
        }
        this->setLifeSpan(hitNUm);
    }

    string Character::print(){
        return "";
    }
}