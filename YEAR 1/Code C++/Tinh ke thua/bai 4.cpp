#include <iostream>
using namespace std;

class KH{
	protected:
		string ma;
		string hoten;
		int soluong;
    	float dongia;
	public:
		KH(){
		}
		KH(string ma, string hoten, int soluong, float dongia){
			this->ma = ma;
			this->hoten = hoten;
			this->soluong = soluong;
			this->dongia = dongia;
		}
		~KH(){
		}
	string get_Ma(){
		return this->ma;
	}
	string get_Hoten(){
		return this->hoten;
	}
	int get_Soluong(){
		return this->soluong;
	}
	float get_Dongia(){
		return this->dongia;
	}
	void set_Ma(string ma){
		this->ma = ma;
	}
	void set_Hoten(string hoten){
		this->hoten = hoten;
	}
	void set_Soluong(int soluong){
		this->soluong = soluong;
	}
	void set_Dongia(float dongia){
		this->dongia = dongia;
	}
	void Input(){
		fflush(stdin);
		cout<<"Nhap ma KH: ";
		getline(cin, this->ma);
		cout<<"Nhap ho ten: ";
		getline(cin, this->hoten);
		cout<<"Nhap so luong: ";
		cin>>this->soluong;
		cout<<"Nhap don gia: ";
		cin>>this->dongia;
	}
	void Output(){
		cout<<"Ma KH: "<<this->ma<<endl;;
		cout<<"Ho ten: "<<this->hoten<<endl;
		cout<<"So luong: "<<this->soluong<<endl;
		cout<<"Don gia: "<<this->dongia<<endl;
	}
};
class KHVN : public KH{
	private:
		float dinhmuc;
	public:
		KHVN(){
		}
		KHVN(string ma, string hoten, int soluong, float dongia, float dinhmuc):KH(){
			this->dinhmuc = dinhmuc;
		}
		~KHVN(){
		}
	float get_Dinhmuc(){
		return this->dinhmuc;
	}
	void set_Dinhmuc(float dinhmuc){
		this->dinhmuc = dinhmuc;
	}
	void Input(){
		KH::Input();
		fflush(stdin);
		cout<<"Nhap dinh muc: ";
		cin>>this->dinhmuc;
	}
	void Output(){
		KH::Output();
		cout<<"Dinh muc: "<<this->dinhmuc<<endl;
		cout<<"Thanh tien KHVN: "<<tien()<<endl;
	}
		float vuot(){
			return this->soluong - this->dinhmuc;
		}
	float tien(){
		if(this->soluong <= this->dinhmuc){
			return this->soluong *this->dongia;
		}
		else{
			return this->soluong *this->dongia *this->dinhmuc +vuot() *this->dongia *2.5;
		}
	}
};
class KHNN : public KH{
	private:
		string quoctich;
	public:
		KHNN(){
		}
		KHNN(string ma, string hoten, int soluong, float dongia, string quoctich):KH(){
			this->quoctich = quoctich;
		}
		~KHNN(){
		}
	string get_Quoctich(){
		return this->quoctich;
	}
	void set_Quoctich(){
		this->quoctich = quoctich;
	}
	void Input(){
		KH::Input();
		fflush(stdin);
		cout<<"Nhap quoc tich: ";
		getline(cin, this->quoctich);
	}
	void Output(){
		KH::Output();
		cout<<"Quoc tich: "<<this->quoctich<<endl;
		cout<<"Thanh tien KHNN: "<<ttien()<<endl;
	}
	float ttien(){
		return this->soluong * this->dongia;
	}
};
class DSKH {
	private:
		KHVN *ds_khvn[1000];
		int n;
		KHNN *ds_khnn[1000];
		int m;
		int demkhvn = 0;
		int demkhnn =0;
		int tbtienkhnn=0;
	public:
	DSKH(){
		this->n = 0;
		this->m = 0;
	};
	~DSKH(){
		for (int i=0; i<n; i++){
			delete ds_khvn[i];
		}
		for (int i=0; i<m; i++){
			delete ds_khnn[i];
		}
	}
	void NhapDS(){
		while(true){
			cout <<"\tNhap loai KH: "<<endl;
			cout <<"1. Nhap KH Viet Nam:"<<endl;
			cout <<"2. Nhap KH nuoc ngoai:"<<endl;
			cout <<"3. Thoat"<<endl;
			int kh;
			cout <<"Nhap: ";
			cin >>kh;
		if (kh == 1){
			KHVN *khvn = new KHVN();
			khvn->Input();
			ds_khvn[n]= khvn;
			n++;
			demkhvn++;
		}
		else if (kh == 2){
			KHNN *khnn = new KHNN();
			khnn->Input();
			ds_khnn[m]= khnn;
			m++;
			demkhnn++;
		}
		else if(kh = 3){
			break;
        }else{
            cout << "\tLua chon ko dung. Vui long nhap lai!" << endl;
        }
    }
}
    void XuatDS(){
            for(int i = 0; i < n; i++){
                cout << "==Thong tin KH thu " << i+1 << ": " << endl;
                ds_khvn[i]->Output();
                cout<<"Tong so luong KHVN: "<<demkhvn<<endl;
            }
            for(int i = 0; i < m; i++){
                cout << "==Thong tin KH thu " << i+1 << ": " << endl;
                ds_khnn[i]->Output();
                tbtienkhnn+= ds_khnn[i]->ttien() / demkhnn;
                cout<<"Tong so luong KHNN: "<<demkhnn<<endl;
                cout<<"Trung binh thanh tien nguoi nuoc ngoai: "<<tbtienkhnn<<endl;
            }
        }
 
		
	
    void Menu(){
            while(true){
                cout << "\t\t\t===MENU===" << endl;
                cout << "\t\t1. Nhap DS" << endl;
                cout << "\t\t2. Xuat DS" << endl;
                cout << "\t\t3. Thoat" << endl;
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
    DSKH *b = new DSKH();
    b->Menu();
    delete b;
    return 0;
} ;



