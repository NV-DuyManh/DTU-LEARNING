#include <iostream>
#include <cmath>
using namespace std;

class Rectangle{
	private:
		float length,width;
	public:
		Rectangle(){
			this -> length=1.0;
			this -> width=1.0;
		}
		Rectangle(float length,float width){
			this ->length=length;
			this -> width=width;
		}
		void setLength(float length){
			this->length=length;
			}
		float getLength(){
			return length;
		}
		void setWidth(float width){
			this->width=width;
		}
		float getWidth(){
			return width;
		}
	
		double getArea(){
			return length * width;
		}
		double getPerimeter(){
			return (length + width) * 2;
		}
	
};
int main (){
	Rectangle *r1 = new Rectangle(1.2,3.4);
	Rectangle *r2 = new Rectangle();
	r1 -> setLength(5.6);
	r1 -> setWidth(7.8);
	cout <<"length is: "<<  r1->getLength()<<endl;
	cout <<"width is: "<<  r1->getWidth()<<endl;
	
	cout <<"area is: "<<r1->getArea()<<endl;
	cout <<"perimeter is: "<<r1->getPerimeter();
	return 0;}
