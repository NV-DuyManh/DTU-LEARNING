class Sinhvien{
	//thuoc tinh
	public:
		string mssv;
		string hoten;
		float diem;
	
	//phuong thuc
	public:
		void an(){
			cout <<"An com";
		}
		void ngu(){
			cout <<"ngu";
		}
		//ko tham so
		Sinhvien(){
			
		}
		//ham khoiw tao co thong so
		Sinhvien (string mssv, string hoten, float diem){
			this -> mssv = mssv;
			this -> hoten = hoten;
			this -> diem = diem;
		}
		Sinhvien
		//ham huy	
		~Sinhvien(){
			
		}
}; 
int main(){
//	Sinhvien  sv // doi tuong gia tri
	//sv.an();
//	Sinhvien ds1[100];
//	ds1[0]=sv;
//	Sinhvien *sv1 = new Sinhvien(); // doi tuong con tro
//	sv1 -> an();
//	sv1 -> hoten = "Vinh";
//	sv1 -> diem;
//	cout <<sv1 ->hoten;
//	cout <<sv1 -> diem;
	
	return 0;
}
