#include <iostream>
#include <math.h>
using namespace std;

class Circle{
	protected:
		double radius;
	    string color;
	public:
		Circle(){
			this->radius = 1.0;
            this-> color = "red";
		}
		Circle(double radius){
			this->radius = radius;
			this->color = "red";
		}
		Circle(double radius, string color){
			this->radius = radius;
			this->color = color;
		}
	double getRadius(){
		return this->radius;
	}
	string getColor(){
		return this->color;
	}
	void setRadius(double radius){
		this->radius = radius;
	}
	void setColor(string color){
		this->color = color;
	}
	double getArea(){
		return radius * radius *M_PI;
	}
	void Output(){
		cout <<"Radius is: "<<this->radius<<endl;
		cout <<"Color is: "<<this->color<<endl;
	}
};
class Cylinder : public Circle{
	protected:
    	double height;	
    public:
    	Cylinder(){
    		this->height = 1.0;
		}
		Cylinder(double height){
			this->height = height;
		}
		Cylinder(double height, double radius){
			this->height = height;
			this->radius = radius;
		}
		Cylinder(double height, double radius, string color){
			this->height = height;
			this->radius = radius;
			this->color = color;
		}
	double getHeight(){
		return this->height;
	}
	void setHeight(double height){
		this->height = height;
	}
	void Output(){
		cout <<"This is a Cylinder"<<endl;
	}
    double getVolume(){
		return getArea()*height;
	}
};
   int main() {
      Cylinder *cy1 = new Cylinder();
      
      cout << "Radius is " << cy1->getRadius();
      cout << ", Height is " << cy1->getHeight();
      cout << ", Color is " << cy1->getColor();
      cout << ", Base area is " << cy1->getArea();
      cout << ", Volume is " << cy1->getVolume();\
      cout <<endl;


      Cylinder *cy2 = new Cylinder(5.0, 2.0);
   
      cout << "Radius is " << cy2->getRadius();
      cout << ", Height is " << cy2->getHeight();
      cout << ", Color is " << cy2->getColor();
      cout<< ", Base area is " << cy2->getArea();
      cout << ", Volume is " << cy2->getVolume();\
      
      delete cy1;
      delete cy2;
      return 0;
   }


