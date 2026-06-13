#include <iostream>
using namespace std;

class dichvu {
	protected:
		string hoten;
		float gio;
	public:
		dichvu(){
		}
		dichvu(string hoten, float gio){
			this->hoten = hoten;
			this->gio = gio;
		}
		~dichvu(){
		}
	string get_Hoten(){
		return this->hoten;
	}
	float get_Gio(){
		return this->gio;
	}
	void set_Hoten(string hoten){
		this->hoten = hoten;
	}
	void set_Gio(float gio){
		this->gio = gio;
	}
	void Input(){
		fflush(stdin);
		cout<<"Nhap ho ten: ";
		getline(cin, this->hoten);
		cout<<"Nhap so gio thue: ";
		cin>>this->gio;
	}
	void Output(){
		cout<<"Ho ten: "<<this->hoten <<endl;
		cout<<"So gio thue: "<<this->gio<<endl;
	}
};
class xedap : public dichvu{
	public : 
	void Output(){
		dichvu::Output();
		cout <<"Tien thue xe dap: "<<tien()<<endl;
	}
	float tien(){
		if(this->gio <= 1){
			return 10000;
		}
		else if(this->gio >1){
			return 10000+ (this->gio-1)*8000;
		}
	} 
};
class xemay : public dichvu {
	private:
		int loaixe;
		int bienso;
	public:
		xemay(){
		}
		xemay(string hoten, float gio, int loaixe, int bienso):dichvu(){
			this->loaixe = loaixe;
			this->bienso = bienso;
		}
		~xemay(){
		}
	int get_Loaixe(){
		return this->loaixe;
	}
	int get_Bienso(){
		return  this->bienso;
	}
	void set_Loaixe(int loaixe){
		this->loaixe = loaixe;
	}
	void set_Bienso(int bienso){
		this->bienso = bienso;
	}
	void Input(){
		dichvu::Input();
		cout <<"Nhap loai xe: ";
		cin>>this->loaixe;
		cout<<"Nha bien so: ";
		cin>>this->bienso;
	}
	void Output(){
		dichvu::Output();
		cout<<"Loai xe: "<<this->loaixe <<endl;
		cout<<"Bien so: "<<this->bienso<<endl;
		cout<<"Tien thue xe may: "<<ttien()<<endl;
	}
	double ttien(){
		if(this->gio <= 1){
			if(this->loaixe == 100){
				return 150000;
			}
			else if(this->loaixe = 200){
				return 200000;
			}
		}
		else if(this->gio >1){
			if(this->loaixe = 100){
				return 150000 +(this->gio - 1)*100000;
			}
			else if(this->loaixe = 200){
				return 200000 +(this->gio -1)*100000;
			}
	}}
};
class qltt {
	private:
		xedap *ds_xd[1000];
		int n;
		xemay *ds_xm[1000];
		int m;
		
	public:
	qltt(){
		this->n = 0;
		this->m = 0;
	};
	~qltt(){
		for (int i=0; i<n; i++){
			delete ds_xd[i];
		}
		for (int i=0; i<m; i++){
			delete ds_xm[i];
		}
	}
	void NhapDS(){
		while(true){
			cout <<"\tNhap loai xe: "<<endl;
			cout <<"1. Nhap xe dap:"<<endl;
			cout <<"2. Nhap xe may:"<<endl;
			cout <<"3. Thoat"<<endl;
			int kh;
			cout <<"Nhap: ";
			cin >>kh;
		if (kh == 1){
			xedap *xd = new xedap();
			xd->Input();
			ds_xd[n]= xd;
			n++;
		}
		else if (kh == 2){
			xemay *xm = new xemay();
			xm->Input();
			ds_xm[m]= xm;
			m++;
		}
		else if(kh = 3){
			break;
        }else{
            cout << "\tLua chon ko dung. Vui long nhap lai!" << endl;
        }
    }
}
double tongtienxd(){
double tongtien = 0;

	for(int i=0;i<m;i++)
	{
		
			tongtien+=ds_xd[i]->tien();}
		return tongtien;
	};
double tongtienxm(){

double tongtien = 0;
	for(int i=0;i<m;i++)
	{

			tongtien+=ds_xm[i]->ttien();
		return tongtien;
	}};
double tongtienxm200pk(){
double tongtienxm200 = 0;
		double a=0;

	for(int i=0;i<m;i++)
	{
		
		a=ds_xm[i]->get_Loaixe();
		if(a==200)
		{
			tongtienxm200+=ds_xm[i]->ttien();
		}
		
	}
	return tongtienxm200;
};
    void XuatDS(){
            for(int i = 0; i < n; i++){
                cout << "==Thong tin xe dap " << i+1 << ": " << endl;
                ds_xd[i]->Output();
                cout<<"Tong so luong tien thue xe dap: "<<endl;
            }
            for(int i = 0; i < m; i++){
                cout << "==Thong tin xe may " << i+1 << ": " << endl;
                ds_xm[i]->Output();
                cout<<"Tong so luong tien thue xe may: "<<endl;
            }
            cout<<"Tong so luong tien thue xe dap : "<<tongtienxd()<<endl;
            cout<<"Tong so luong tien thue  xe may: "<<tongtienxm()<<endl;
            cout<<"Tong so luong tien thue  xe may 200 phan khoi: "<<tongtienxm200pk()<<endl;
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
    qltt *b = new qltt();
    b->Menu();
    delete b;
    return 0;
};

