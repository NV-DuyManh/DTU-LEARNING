#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;
    string color;

public:
    Circle() {
        radius = 1.0;
        color = "red";
    }

    Circle(double r) {
        radius = r;
        color = "red";
    }

    double getRadius() {
        return radius;
    }

    double getArea() {
        return M_PI *  radius * radius;
    }
};

int main() {
    Circle*c1 = new Circle();
    Circle*c2 = new Circle(2.0);

    cout << "The circle has radius of " << c1->getRadius() << ", and area of " << c1->getArea() << endl;
    cout << "The circle has radius of " << c2->getRadius() << ", and area of " << c2->getArea() << endl;

    return 0;
}

