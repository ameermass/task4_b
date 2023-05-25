#pragma once 

#include "Character.hpp"
#include "iostream"
using namespace std;

namespace ariel{


    class Cowboy : public Character{

        private:
        string _name;
        Point _point;

        int bull;

        public:


        Cowboy(string name, Point point);
        Cowboy(string name, Point point, int hp);
        string print() override;
        void attack(Character* enemy) override;
        void shoot(Character* c);


        bool hasboolets();

        int getBull(){
            return this->bull;
        }

        void reload();

        


    };
}