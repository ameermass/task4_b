#pragma once 
#include <iostream>
#include <cmath>

#include "Point.hpp"
using namespace std;


namespace ariel{


    class Character{

        private:
        string name;
        Point point;
        int lifeSpan;
        bool alreadyInTeam;

        public:

        Character(string name,const Point& point);
        Character(string name,const Point& point, int _hp);
        Character();

        bool isAlive();
        virtual string print();
        double distance(Character*) ;
        void hit(int hitNUm);
        virtual void attack(Character*) = 0;

        void setAlreadyInTeam(bool flag){
            alreadyInTeam = flag;
        }

        bool getAlreadyInTeam(){
            return alreadyInTeam;
        }

        int getLifeSpan(){
            return this->lifeSpan;
        }

        void setLifeSpan(int num){
            this->lifeSpan -= num;
        }

        string getName(){
            return this->name;
        }

        Point getLocation(){
            return this->point;
        }

        void setLocation(const Point& loc){
            this->point = loc;
        }

        virtual ~Character() = default;

    };
}