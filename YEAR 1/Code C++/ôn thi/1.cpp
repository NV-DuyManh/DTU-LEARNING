#include <iostream>
#include <vector>
using namespace std;

class Xe{
	protected:
		string ten;
		float gio;
	public:
		Xe(){
		}
		Xe(string ten, float gio){
			this->ten = ten;
			this->gio = gio;
		}
		~Xe(){
		}
	string get_ten(){
		return this->ten;
    }
	float get_gio(){
		return this->gio;
	}
	
	void set_ten(string ten){
		this->ten = ten;
	}
	void set_gio(float gio){
		this->gio = gio;
	}
	virtual void Input(){
		fflush(stdin);
		cout <<"Nhap ten: ";
		getline(cin, this->ten);
		cout <<"Nhap gio thue: ";
		cin >>this->gio;
	} 
	virtual void Output(){
		cout <<"Ten: "<<this->ten<<endl;
		cout <<"Gio thue: "<<this->gio<<endl;
	}
	virtual float tien(){
		float tienthue = 0;
	}

};

class Xedap : public Xe{
	public:
	    void Output(){
	    	Xe::Output();
	    	cout<<"Tien thue xe dap: "<<tien()<<endl;
		}
		~Xedap(){
		};
	float tien(){
		Xe::tien();
		if(this->gio <=1){
			return 10000;
		}else{
			return 10000 +(this->gio-1)*8000;
		}
	}		
};
class Xemay : public Xe {
private:
    int loaixe;
    int bienso;

public:
    Xemay() {
    }

    Xemay(string ten, float gio, int loaixe, int bienso) : Xe() {
        this->loaixe = loaixe;
        this->bienso = bienso;
    }

    ~Xemay() {
    }

    int get_Loaixe() {
        return this->loaixe;
    }

    int get_Bienso() {
        return this->bienso;
    }

    void set_Loaixe(int loaixe) {
        this->loaixe = loaixe;
    }

    void set_Bien(int bienso) {
        this->bienso = bienso;
    }

    void Input() {
        Xe::Input();
        fflush(stdin);
        cout << "Nhap loai xe: ";
        cin >> this->loaixe;
        cout << "Nhap bien so: ";
        cin >> this->bienso;
    }

    void Output() {
        Xe::Output();
        cout << "Loai xe: " << this->loaixe << endl;
        cout << "Bien so: " << this->bienso << endl;
        cout << "Tien thue xe may: " << tien() << endl;
    }

    float tien() {
        Xe::tien();
        if (this->gio <= 1) {
            if (this->loaixe == 100) {
                return 150000;
            } else if (this->loaixe == 200) {
                return 200000;
            } else {
                cout << "Loi!!";
            }
        } else {
            if (this->loaixe == 100) {
                return 150000 + (this->gio - 1) * 100000;
            } else if (this->loaixe == 200) {
                return 200000 + (this->gio - 1) * 100000;
            } else {
                cout << "Loi!!";
            }
        }
    }
};
class ql {
private:
    vector<Xe*> ds;

public:
    ql() {
    }

    ~ql() {
        for (int i = 0; i < ds.size(); i++) {
            delete ds[i];
        }
        ds.clear();
    }

    void NhapDs() {
        while (true) {
            cout << "1. Nhap xe dap" << endl;
            cout << "2. Nhap xe may" << endl;
            cout << "3. Thoat" << endl;
            int lc;
            cout << "Nhap lua chon: ";
            cin >> lc;
            if (lc == 1) {
                Xe* xd = new Xedap();
                xd->Input();
                ds.push_back(xd);
            } else if (lc == 2) {
                Xe* xm = new Xemay();
                xm->Input();
                ds.push_back(xm);
            } else if (lc == 3) {
                break;
            } else {
                cout << "Lua chon khong hop le!" << endl;
            }
        }
    }

    void XuatDs() {
        for (int i = 0; i < ds.size(); i++) {
            cout << "Thong tin xe thu " << i + 1 << " la: ";
            ds[i]->Output();
        }
    }

    void Menu() {
        while (true) {
            cout << "=== Menu ===" << endl;
            cout << "1. Nhap danh sach" << endl;
            cout << "2. Xuat danh sach" << endl;
            cout << "3. Tong tien xe dap va xe may" << endl;
            cout << "4. Tong tien xe may 200pk" << endl;
            cout << "5. Thoat" << endl;
            int l;
            cout << "Nhap lua chon: ";
            cin >> l;
            if (l == 1) {
                NhapDs();
            } else if (l == 2) {
                XuatDs();
            } else if (l == 3) {
                cout << "Tien thue xe dap: " << tien() << endl;
                cout << "Tien thue xe may: " << ttien() << endl;
                cout << "Tong tien 2 xe: " << tttien() << endl;
            } else if (l == 4) {
                cout << "Tong tien xe may 200pk: " << ttien200() << endl;
            } else if (l == 5) {
                break;
            } else {
                cout << "Lua chon khong hop le!" << endl;
            }
        }
    }

    float tien() {
        float tong = 0;
        for (int i = 0; i < ds.size(); i++) {
            if (dynamic_cast<Xedap*>(ds[i])) {
                tong += ds[i]->tien();
            }
        }
        return tong;
    }

    float ttien() {
        float ttong = 0;
        for (int i = 0; i < ds.size(); i++) {
            if (dynamic_cast<Xemay*>(ds[i])) {
                ttong += ds[i]->tien();
            }
        }
        return ttong;
    }

    float tttien() {
        float tttong = 0;
        for (int i = 0; i < ds.size(); i++) {
            tttong += ds[i]->tien();
        }
        return tttong;
    }

    float ttien200() {
        float ttong = 0;
        for (int i = 0; i < ds.size(); i++) {
            if (dynamic_cast<Xemay*>(ds[i]) && ds[i]->get_Loaixe() == 200) {
                ttong += ds[i]->tien();
            }
        }
        return ttong;
    }
    void SapXep() {
            for (int i = 0; i < ds.size() - 1; i++) {
                for (int j = 0; j < ds.size() - i - 1; j++) {
                    if (ds[j]->get_Ten > ds[j + 1]->get_Ten()) {
                        swap(ds[j], ds[j + 1]);
                    }
                }
            }
            XuatDs(); 
        }
};


int main(){
	ql *a=new ql;
	a->Menu();
	delete a;
	return 0;
}






















