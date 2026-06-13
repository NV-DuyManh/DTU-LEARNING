#include<iostream>
using namespace std;
/*
- Tu khoa static duoc su dung

-Tat ca cac doi tuong duoc tao ra tu 1 lop va duoc chia se chung cac thuoc tinh 
va phuong thuc static cu lop do



*/


class Home{
	private:
		float chieudai;
		float chieurong;
	public:
		static int ao;
		Home(){
			ao++;
		}
		static float dientich(float cd, float cr){
			return cd*cr;
		}
};

int Home::ao = 0;

int main(){
	Home h1;
	Home h2;
	cout << Hone::ao;
	cout << 
	

	
	
	return 0;
}
