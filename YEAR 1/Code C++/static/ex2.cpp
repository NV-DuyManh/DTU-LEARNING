#include <iostream>
#include <cmath>
using namespace std; class Point{
    private:
        float x;
        float y;
    public:
        Point(){
            
        }
        Point(float x, float y){
            this->x = x;
            this->y = y;
        }
        
        Point Tru(Point p){
            Point tam;
            tam.x = this->x - p.x;
            tam.y = this->y - p.y;
            return tam;
        }
        Point operator - (Point &p){
            Point tam;
            tam.x = this->x - p.x;
            tam.y = this->y - p.y;
            return tam;
        }
        
        float Distance(){
        	return sqrt(this->x * this->x + this->y * this->y);
		}
        void Output(){
            cout << "P(" << this->x <<", " << this->y << ")" << endl; 
        }
        friend Point Tru(Point p1, Point p2);
};

int main(){
    Point p1(1, 2);
    p1.Output();
    Point p2(3, 4);
    p2.Output();
    Point p3 = p1 - p2;
    p3.Output();

    cout <<"Distance: "<<p3.Distance();
    return 0;
} 

