#include <iostream>
using namespace std;

/*
overloading operator

*/



class phanso{
	private:
		int tu;
		int mau;
	public:
		phanso(){
			
		}
		phanso(int tu, int mau){
			this->tu = tu;
			this->mau = mau;
		}
		//copy constructor
		phanso(const phanso &ps_other){
			this->tu = ps_other.tu;
			this->mau = ps_other.mau;
		}
		
		void operator = (const phanso &ps_other){
			this->tu = ps_other.tu;
			this->mau = ps_other.mau;
		}
		
		~phanso(){
		}
		
		friend istream& operator >> (istream& is, phanso &sv){
			cout <<"nhap tu: ";
			cin >>sv.tu;
			cout <<"nhap mau: ";
			cin>>sv.mau;
			return is;
		}
		
		phanso void cong(const phanso &sv){
			phanso tam;
			tam.tu - this->tu 
		}
		
		friend ostream& operator << (ostream& is, phanso &sv){
			cout <<sv.tu <<"/"<<sv.mau <<endl;
			
		}
		void input(){
			cout <<"nhap tu: ";
			cin >>this->tu;
			cout <<"nhap mau: ";
			cin>>this->mau;
		}
		void output(){
			cout <<this->tu <<"/"<<this->mau<<endl ;
		}
};
int main(){
	
	
	
	
	phanso p1(1,2);
	cin >>p1;
	cout <<p1;
//	p1.input();
//	p1.output();
//	phanso p2(p1);
//	p2.output();
	p2 = p1;
	phanso p2;
	phanso p3 = p1.cong(p2);
	cout << p3; 
	return 0;
	
}
