#include "Point.hpp"

namespace ariel {

    Point::Point(double x, double y) : _x(x), _y(y){}
    Point::Point(){}

    // print: Point: (x, y)
    string Point::print(){
        return "Point: (" + to_string(this->_x) + ", " + to_string(this->_y) + ")" ;
    }

    double Point::distance(const Point& point){
        double subX = point._x - this->_x;
        double subY = point._y - this->_y;

        double sum =  (subX * subX) + (subY * subY);

        return sqrt(sum);
    }

    Point Point::moveTowards(const Point& src, const Point& dst, double dist){

        if(dist < 0){
            throw std::invalid_argument("Distance cannot be negative");
        }

        double dx = dst._x - src._x;
        double dy = dst._y - src._y;

        // Calculate the actual distance using sqrt
        double actualDist = sqrt((dx * dx) + (dy * dy));

        if(actualDist <= dist){
            return dst;
        }

        // Normalize the distance vector
        dx /= actualDist;
        dy /= actualDist;

        // Move towards dst by dist along the normalized vector
        double newX = src._x + dx * dist;
        double newY = src._y + dy * dist;

        return Point(newX, newY);
    }


}