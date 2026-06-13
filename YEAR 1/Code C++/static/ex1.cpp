#include <iostream>
using namespace std;

class Rectangle {
	private:
		float length ,width;
	public:
		Rectangle(){
			
		}
		Rectangle(float length, float width){
			this->length = length;
			this->width = width;
		}
		~Rectangle(){
		}
	float Area(){
		return this->length * this->width;
	}
	friend void display (Rectangle a);	
};
void display(Rectangle a){
	cout <<"Chieu dai: "<<a.length<<endl;
	cout <<"Chieu rong: "<<a.width<<endl;
	cout <<"Dien tich: "<<a.Area()<<endl;
}
int main(){

	Rectangle a(2,5);
	display(a);
	return 0;
}
