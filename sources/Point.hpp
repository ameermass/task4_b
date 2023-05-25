#pragma once 
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

namespace ariel{


    class Point{

        private:

        double _x;
        double _y;

        
        public:

        Point();
        Point(double x, double y);

        double distance(const Point& point);
        string print();

        static Point moveTowards(const Point& src, const Point& dst, double dist);


        double getX(){
            return this->_x;
        }

        double getY(){
            return this->_y;
        }
        
    };
}