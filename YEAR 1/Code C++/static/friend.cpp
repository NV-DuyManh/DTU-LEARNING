#include <iostream>
using namespace std;

/*
friend function
friend class

*/
class Sinhvien{
	private:
		string name;
		float diem;
	public:
		Sinhvien(){
			
		}
		Sinhvien(string name, float diem){
			this->name = name;
			this->diem = diem;
		}
		float getDiem(){
			return this->diem;
		}
		friend string lay_name(Sinhvien sv);
		friend class giangvien;
};

class giangvien{
	public:
		void Update(Sinhvien &sv, float diem){
			sv.diem = diem;
		}
};


string lay_name(Sinhvien sv){
	return sv.name;
}

int main(){
	Sinhvien sv("Vinh", 10);
//	cout << lay_name(sv);
	giangvien gv;
	gv.Update(sv,5);
	cout << sv.getDiem();
	
	return 0;
}
