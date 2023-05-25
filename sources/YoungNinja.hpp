#pragma once 

#include "iostream"

#include "Ninja.hpp"
using namespace std;

namespace ariel{


    class YoungNinja : public Ninja{

        private:
        string _name;
        Point _point;

        public:
        YoungNinja(string name,const Point& point);


    };
}