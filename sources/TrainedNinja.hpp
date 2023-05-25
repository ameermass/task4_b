#pragma once 

#include "iostream"

using namespace std;

#include "Ninja.hpp"

namespace ariel{


    class TrainedNinja : public Ninja{

        private:
        string _name;
        Point _point;

        public:
        TrainedNinja(string name,const Point& point);

    };
}