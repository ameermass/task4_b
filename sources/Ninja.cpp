#include "Ninja.hpp"

namespace ariel{

    Ninja::Ninja(string name,const Point& point):Character(name, point){}

    Ninja::Ninja(string name,const Point& point, int _hp, int speed):Character(name, point,_hp),speed(speed){}



    void Ninja::slash(Character* c) {
        if(c == nullptr){
            throw std::runtime_error("The Character is null");
        }
        else if(!isAlive() || !c->isAlive()){
            throw std::runtime_error("The Character is not alive");
        }
        else if(this == c){ 
            throw std::runtime_error("Can't attack ypurself");
        }
        else{
            double dist = this->distance(c);
            if(dist < 1){
                c->hit(40);
            }
        }
    }

    void Ninja::move(Character* otherCharacter){
        double dist = this->getLocation().distance(otherCharacter->getLocation());
        
        if (dist <= speed) {
            this->setLocation(otherCharacter->getLocation());

        } else {
            double ratio = speed / dist;
            double new_X = this->getLocation().getX() + (otherCharacter->getLocation().getX() - this->getLocation().getX()) * ratio;
            double new_Y = this->getLocation().getY() + (otherCharacter->getLocation().getY() - this->getLocation().getY()) * ratio;
            this->setLocation(Point(new_X, new_Y));
        }
    }

    string Ninja::print(){
        if (!isAlive()) {
            return "Character Type : N\nCharacter Name : (" + this->getName() + ")\nCharacter Location : " + this->getLocation().print();
        } else {
            return "Character Type : N\nCharacter Name : " + this->getName() + "\nCharacter Location : " + this->getLocation().print()
            + "\nCharacter HP : " + to_string(this->getLifeSpan()) ;
        }
    }

    void Ninja::attack(Character* target) {
        // Implementation for Ninja attack
        this->slash(target);
    }
    
}