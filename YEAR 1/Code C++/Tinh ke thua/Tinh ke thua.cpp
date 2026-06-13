#include<iostream>
using namespace std;
/*
     TINH KE THUA(INHERITANCE)
- Tinh ke thua cho phep lop moi duoc tao tu 1 lop da ton tai
- Lop moi duoc tao ra con goi la lop con (subclass)
- Lop ton tai duoc goi la lop cha(super class)
- Tinh ke thua cho phep lop con thua huong nhung thuoc tinh va phuong thuc cua lop cha
.protected
*/
class Animal{
	public:
		int tuoi;
	public:
		void Ngu(){
			cout<<"animal dang ngu"<<endl;
		}
		void An(){
			cout<<"animal dang an"<<endl;
		}
};
class Cat : public Animal{
	public:
		void An(){
			cout << "Cat dang an ca"<<endl;
		}
};
class Dog : public Animal{
	public:
    	void An(){
			cout << "Dog dang an xuong"<<endl;
		}
};
int main(){
	Cat *cat = new Cat();
	cat->Ngu();
	cat->An();
	Dog *dog = new Dog();
	dog->Ngu();
	dog->An();
	
	return 0;
}



