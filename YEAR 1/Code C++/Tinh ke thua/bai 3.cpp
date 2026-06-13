#include <iostream>
using namespace std;

class Book{
	protected:
		string ma;
		float dongia;
		int soluong;
		string nxb;
	public:
		Book(){
		};
		Book(string ma, float dongia, int soluong, string nxb){
			this->ma = ma;
			this->dongia = dongia;
			this->soluong = soluong;
			this->nxb = nxb; 
		}
		~Book(){
		}
	string get_Ma(){
		return this->ma;
	}
	float get_Dongia(){
		return this->dongia;
	}
	int get_Soluong(){
		return this->soluong;
	}
	string get_Nxb(){
		return this->nxb;
	}
	void set_Ma(string ma){
		this->ma = ma;
	}
	void set_Dongia(float dongia){
		this->dongia = dongia;
	}
	void set_Soluong(int soluong){
		this->soluong = soluong;
	}
	void set_Nxb(string nxb){
		this->nxb = nxb;
	}
	void Input(){
		fflush(stdin);
		cout <<"Nhap ma sach: ";
		getline(cin, this->ma);
		cout <<"Nhap don gia: ";
		cin >>this->dongia;
		cout<<"Nhap so luong: ";
		cin >>this->soluong;
		fflush(stdin);
		cout <<"Nhap nha xuat ban: ";
		getline(cin, this->nxb);
	}
	void Output(){
		cout <<"Ma sach: "<< this->ma<<endl;
		cout <<"Don gia: "<< this->dongia<<endl;
		cout <<"So luong: "<<this->soluong<<endl;
		cout <<"Nha xuat ban: "<<this->nxb<<endl;
	}
};
class SGK : public Book{
	private:
		string tinhtrang;
	public:
		SGK(){
			
		};
		SGK(string ma, float dongia, int soluong, string nxb, string tinhtrang):Book(ma, dongia, soluong, nxb){
			this->tinhtrang = tinhtrang;
		}
	string get_Tinhtrang(){
		return this->tinhtrang;
	}
	~SGK(){
	}
	void set_Tinhtrang(string tinhtrang){
		this->tinhtrang = tinhtrang;
	}
	void Input(){
		Book::Input();
		fflush(stdin);
		cout <<"Nhap tinh trang: ";
		cin>> this->tinhtrang;
		}
	void Output(){
		Book::Output();
		cout <<"Tinh trang: "<<this->tinhtrang<<endl;
		cout <<"Thanh tien: "<<this->tien()<<endl;
	}
	float tien(){
		if(this->tinhtrang == "moi"){
			return this->soluong * this->dongia;
		}
		else if(this->tinhtrang == "cu"){
			return this->dongia * this->soluong *50/100;
		}
		else{
			cout <<"Nhap sai!!";
		}
	}
};
class STK : public Book{
	private:
		float thue;
	public:
		STK(){
		}
		STK(string ma, float dongia, int soluong, string nxb, string tinhtrang, float thue):Book(){
			this->thue = thue;
		}
		~STK(){
		};
	float get_Thue(){
		return this->thue;
	}
	void set_Thue(float thue){
		this->thue = thue;
	}
	void Input(){
		Book::Input();
		cout <<"Nhap thue: ";
		cin >> this->thue;
	}
	void Output(){
		
		Book::Output();
		cout <<"Thue: "<<this->thanhtien()<<endl;
	}
	float thanhtien(){
		return this->soluong * this->dongia + this->thue;
	}
};
class BookManager : public Book{
	private:
		Book *ds_sgk[1000];
		int n;
		Book *ds_stk[1000];
		int m;
	public:
	BookManager(){
		this->n = 0;
		this->m = 0;
	};
	~BookManager(){
		for (int i=0; i<n; i++){
			delete ds_sgk[i];
		}
		for (int i=0; i<m; i++){
			delete ds_stk[i];
		}
	}
	void NhapDS(){
		while(true){
			cout <<"\tNhap loai sach: "<<endl;
			cout <<"1. Nhap sach giao khoa"<<endl;
			cout <<"2. Nhap sach tham khao"<<endl;
			cout <<"3. Thoat"<<endl;
			int sach;
			cout <<"Nhap sach: ";
			cin >>sach;
		if (sach == 1){
			SGK *sgk = new SGK();
			sgk->Input();
			ds_sgk[n]= sgk;
			n++;
		}
		else if (sach == 2){
			STK *stk = new STK();
			stk->Input();
			ds_stk[m]= stk;
			m++;
		}
		else if(sach = 3){
			break;
        }else{
            cout << "\tLua chon ko dung. Vui long nhap lai!" << endl;
        }
	}}

 void XuatDS(){
            int index = 1;
            for(int i = 0; i < n; i++){
                cout << "==Thong tin sach thu " << index << ": " << endl;
                ds_sgk[i]->Output();
                index++;
            }
            for(int i = 0; i < m; i++){
                cout << "==Thong tin sach thu " << index << ": " << endl;
                ds_stk[i]->Output();
                index++;
            }
        }
        void Menu(){
            while(true){
                cout << "\t\t\t===MENU===" << endl;
                cout << "\t\t1. Nhap DS" << endl;
                cout << "\t\t2. Xuat DS" << endl;
                cout << "\t\t0. Thoat" << endl;
                int luachon;
                cout << "Nhap lua chon: ";
                cin >> luachon;
                if(luachon == 1){
                    NhapDS();
                }else if(luachon == 2){
                    XuatDS();
                }else if(luachon == 0){
                    break;
                }else{
                    cout << "Lua chon khong dung!" << endl;
                }
            }
        }
};
int main(){
    BookManager *b = new BookManager();
    b->Menu();
    delete b;
    return 0;
} 
		
	
	



	
