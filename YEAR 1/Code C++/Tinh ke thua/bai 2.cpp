#include <iostream>
using namespace std;

class Point2D{
	protected:
		int x;
    	int y;
	public:
		Point2D(){
			this->x = 0;
			this->y = 0;
		}
		Point2D(int x, int y){
			this->x = x;
			this->y = y;
		}
	int getX(){
		return this->x;
	}
	int getY(){
		return this->y;
	}
	void setX(int x){
		this->x = x;
	}
	void setY(int y){
		this->y = y;
	}

	void Output(){
		cout <<"("<<this->x<<","<<this->y<<")"<<endl;
	} 
};
class Point3D : public Point2D{
	protected:
		int z;
	public:
		Point3D(){
			this->z = 0;
		}
		Point3D(int x, int y, int z){
			this->x = x;
			this->y = y;
			this->z = z;
		}
	int getZ(){
		return this->z;
	}
	void setZ(int z){
		this->z = z;
	}
	void toString(){
		
		cout <<"("<<this->x<<","<<this->y<<","<<this->z<<")"<<endl;
	}
};
int main() {
  Point2D *p2a = new Point2D(1,2);
  p2a->Output();
  Point2D *p2b = new Point2D();
  p2b->Output();
  
  p2a->setX(3);
  p2a->setY(4);
  
  p2a->Output();
  
  cout<<"X is: "<<p2a->getX()<<endl;
  cout<<"Y is: "<<p2a->getY()<<endl;
  delete p2a;
  delete p2b;
  
  Point3D *p3a = new Point3D(11,12,13);
  p3a->toString();

  Point2D *p3b = new Point3D();
  p3b->Output();
  p3a->setX(21);
  p3a->setY(22);
  p3a->setZ(23);
  p3a->toString();
  cout << "x is: " << p3a->getX() << endl;   
  cout << "y is: " << p3a->getY() << endl;    
  cout << "z is: " << p3a->getZ() << endl;    
  
  
  delete p3a;
  delete p3b;
  return 0;
}

