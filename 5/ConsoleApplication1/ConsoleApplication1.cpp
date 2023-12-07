#include <iostream>
#include <cmath>
using namespace std;
class RavnStTriangle {
public:
    double sideLength;

public:
    RavnStTriangle(double side) : sideLength(side) {}

    double getHeight() const {
        return sideLength * sqrt(3) / 2;
    }

    double getBisector() const {
        return sqrt(3) / 2 * sideLength;
    }

    double getPerimeter() const {
        return 3 * sideLength;
    }

    double getArea() const {
        return (sqrt(3) / 4) * sideLength * sideLength;
    }


};

class PravilnPyramid : public RavnStTriangle {
private:
    double apothem;

public:
    PravilnPyramid(double side, double apothem) : RavnStTriangle(side), apothem(apothem) {}

    double getVolume() const {
        return (1.0 / 3) * RavnStTriangle::getArea() * apothem;
    }

    double getArea(double s) const {
        double Area = s * 3 + RavnStTriangle::getArea();
        return Area;
        
    }

};

int main() {
    setlocale(LC_ALL, "RUS");
    RavnStTriangle triangle(5);
    PravilnPyramid pyramid(5,7);

    cout << "Высота треугольника: " << triangle.getHeight() << endl;
    cout << "Биссектриса треугольника: " << triangle.getBisector() << endl;
    cout << "Периметр треугольника: " << triangle.getPerimeter() << endl;
    cout << "Площадь треугольника: " << triangle.getArea() << endl;

    cout << "Объем Пирамиды: " << pyramid.getVolume() << endl;
    cout << "Площадь Пирамиды: " << pyramid.getArea(5) << endl;

    return 0;
}