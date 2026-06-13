#include <iostream>
#include <vector>

using namespace std;

class sanpham {
	private :
		string ten;
		int soluong;
		float dongia;
	public :
		sanpham(){
		}
		sanpham(string ten, int soluong, float dongia)
		{
			this->ten=ten;
			this->soluong=soluong;
			this->dongia=dongia;
		}
		~sanpham(){
		}
		float getdongia(){
			return this->dongia;
		};
		int getsoluong(){
			return this->soluong;
		};
		string getten(){
			return this->ten;
		}
		void setten(string ten)
		{
			this->ten=ten;
		}
		
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"Ten san pham : ";
			getline(cin, this->ten);
			cout<<"So luong san pham : ";
			cin>>this->soluong;
			cout<<"Don gia san pham : ";
			cin>>this->dongia;
		}
		virtual void hienthi()
		{
			cout<<"San pham ten : "<<ten<<endl;
			cout<<"San pham co so luong : "<<soluong<<endl;
			cout<<"San pham co gia : "<<dongia<<endl;
		}
		virtual float thanhtien() =0;
};
class tieudung:public sanpham{
	private:
		string hangsx;
	public:
	tieudung(){
	}	
	tieudung(string ten,int soluong,float dongia,string hangsx):sanpham(ten,soluong,dongia){
		this->hangsx=hangsx;		
	}
	
	float thanhtien(){	
		return getdongia()*getsoluong(); 		
	};
	void nhap(){
		sanpham::nhap();
		fflush(stdin);
		cout<<"Hang san xuat:";
		getline(cin, this->hangsx);
		
	}
	void hienthi(){
		sanpham::hienthi();
		cout<<"Thanh tien :"<<thanhtien()<<endl;			
	}		
};
class thucpham:public sanpham{
	private:
		int hansd;
	public:
		thucpham(){
		}
		thucpham(string ten,int soluong,float dongia,int hansd):sanpham(ten,soluong,dongia){
		this->hansd=hansd;
		}
		int gethansd(){
			return this->hansd;
		};
		
		float thanhtien(){
	return getdongia()*getsoluong(); 				
	};
	void nhap(){
		sanpham::nhap();
		fflush(stdin);
		cout<<"Han su dung (ngay):";
		cin>>this->hansd;
		
		
	}
	void hienthi(){	
		sanpham::hienthi();
		cout<<"Thanh tien:"<<thanhtien()<<endl;	
	}			 
};
class qlisanpham{
	private:
		vector<sanpham*> ds;
	public:
		~qlisanpham(){
			for(int i = 0 ; i < ds.size() ; i++){
				delete ds[i];
			}
			ds.clear();
		}
		
		void nhapds(){
			while(true){
				cout << "\t\t\t====Lua chon loai san pham====" << endl;
				cout << "\t\t1. Thuc pham." << endl;
				cout << "\t\t2. Tieu dung." << endl;
				cout << "\t\t3. Thoat. " << endl;
				int luachon;
				cout << "\tNhap lua chon : ";
				cin >> luachon;
				if(luachon == 1){
					sanpham *a = new thucpham();
					a->nhap();
					ds.push_back(a);
				}
				
				else if(luachon == 2){
					sanpham *b = new tieudung();
					b->nhap();
					ds.push_back(b);
				}
				
				else if(luachon == 3){
					break;
				}
				
				else{
					cout << "Lua chon khong hop le!" << endl;
				}
			}
		}
		
		void xuatds(){
			int danhsach = 1;
			for(int i = 0 ; i < ds.size() ; i++){
				cout << "\t==Thong tin san pham thu " << danhsach << " : " << endl;
				ds[i]->hienthi();
				danhsach++;
			}
		}
		
		void doanhthu(){
			float tongthanhtien = 0;
			for(int i = 0 ; i < ds.size() ; i++){
				tongthanhtien+= ds[i]->thanhtien();
			}
			cout << "Doanh thu : "<<tongthanhtien<<endl;
			
		}
		
		void quahan(){
    		cout << "\tCac san pham qua han : ";
    			for (int i = 0; i < ds.size(); i++) {
    				if(dynamic_cast<thucpham*>(ds[i])!= NULL){
					thucpham*a=dynamic_cast<thucpham*>(ds[i]);
        			if (a->gethansd()<= 10) { 
            			cout << a->getten() << " - Han su dung : " << a->gethansd()<< " ngay."<<endl;
        		}
        		
				}
				else {
        			cout<<"Khong co san pham qua han su dung!";
    		}
		}
}
		void doanhthucaonhat() {
    		sanpham *spcaonhat = ds[0];
    		float doanhthucaonhat = ds[0]->thanhtien();
    			for (int i = 1; i < ds.size(); i++) {
        			if (ds[i]->thanhtien() > doanhthucaonhat) {
            			doanhthucaonhat = ds[i]->thanhtien();
            			spcaonhat = ds[i];
        		}
    		}
    		cout << "San pham co doanh thu cao nhat: " << spcaonhat->getten() << " voi doanh thu la: " << doanhthucaonhat << endl;
		}

		
		void menu(){
			while(true){
				cout << "\t\t\t\t=====Menu=====" << endl;
				cout << "\t\t1. Nhap thong tin san pham." << endl;
				cout << "\t\t2. Xuat thong tin san pham, thanh tien." << endl;
				cout << "\t\t3. Doanh thu cua tieu dung va thuc pham." << endl;
				cout << "\t\t4. Thuc pham sap het han su dung. " << endl;
				cout << "\t\t5. San pham co doanh thu cao nhat." << endl;
				cout << "\t\t6. Thoat." << endl;
				int luachon;
				cout << "\tNhap lua chon : ";
				cin >> luachon;
				if(luachon == 1){
					nhapds();
				}
				else if(luachon == 2){
					xuatds();
				}
				else if(luachon == 3){
					doanhthu();
				}
				else if(luachon == 4){
					quahan();
				}
				else if(luachon == 5){
					doanhthucaonhat();
				}
			
				else if(luachon == 6){
					break;	
				}
				else{
					cout << "Lua chon khong hop le!"<< endl;
				}
			}
		}
};
int main(){
	qlisanpham *a=new qlisanpham();
	a->menu();
	return 0;
};
