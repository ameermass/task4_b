#pragma once

#include "Character.hpp"
using namespace std;

namespace ariel{

    class Ninja : public Character{

        public:

        int speed;
        Ninja(string name,const Point& point);
        Ninja(string name,const Point& point, int _hp, int speed);
        void slash(Character* character);
        void move(Character* otherCharacter);
        string print() override;
        void attack(Character*) override;
        

        int getSpeed(){
            return this->speed;
        }


        string getName(){
            return "";
        }
        
    };
}