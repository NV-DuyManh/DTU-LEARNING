#include <iostream>
using namespace std;
class sophuc{
	private:
		float a,b;
	public:
		sophuc(){
			this->a = 0;
			this->b = 0;
		}
		sophuc(float a, float b){
			this->a = a;
			this->b = b;
		}
	float get_A(){
		return this->a;
	}
	float get_B(){
		return this->b;
	}
	void set_A(float a){
	    this->a = a;
	}
	void set_B(float b){
		this->b = b;
	}
	void nhap(){
		cout<<"Nhap so phuc(a+bi)"<<endl;
		cout <<"Nhap a: ";
		cin >>this->a;
		cout <<"Nhap b: ";
		cin >>this->b;
	}
	void xuat(){
		cout <<"ket qua so phuc can tim la: "<<a<<"+"<<b<<"i";
	}
	sophuc cong(sophuc other) {
        return sophuc(a + other.a, b + other.b);
    }
    sophuc tru(sophuc other) {
        return sophuc(a - other.a, b - other.b);
    }
    sophuc nhan(sophuc other) {
        float real = a * other.a - b * other.b;
        float imag = a * other.b + b * other.a;
        return sophuc(real, imag);
    }
    sophuc chia(sophuc other) {
        float denominator = other.a * other.a + other.b * other.b;
        float real = (a * other.a + b * other.b) / denominator;
        float imag = (b * other.a - a * other.b) / denominator;
        return sophuc(real, imag);
    }
	void Menu(){
    sophuc other;
    while (true){
        cout<<"\t\t\t===Menu==="<<endl;
        cout<<"\t\t1. Nhap danh sach: "<<endl;
        cout<<"\t\t2. Xuat danh sach:"<<endl;
        cout<<"\t\t3. Cong(+)"<<endl;
        cout<<"\t\t4. Tru(-)"<<endl;
        cout<<"\t\t5. Nhan(*)"<<endl;
        cout<<"\t\t6. Chia(/)"<<endl;
        cout<<"\t\t7. Thoat"<<endl;
        int pheptinh;
        cout <<"\tNhap lua chon: ";
        cin>>pheptinh;
        if(pheptinh == 1){
            nhap();
        }else if(pheptinh == 2){
            cout <<"Danh sach ket qua: "<<endl;
            xuat();
        }else if(pheptinh == 3){
            cout << "Nhap so phuc can cong: ";
            other.nhap();
            sophuc result = cong(other);
            result.xuat();
        }else if(pheptinh == 4){
            cout << "Nhap so phuc can tru: ";
            other.nhap();
            sophuc result = tru(other);
            result.xuat();
        }else if(pheptinh == 5){
            cout << "Nhap so phuc can nhan: ";
            other.nhap();
            sophuc result = nhan(other);
            result.xuat();
        }else if(pheptinh == 6){
            cout << "Nhap so phuc can chia: ";
            other.nhap();
            sophuc result = chia(other);
            result.xuat();
        }else if(pheptinh == 7){
            break;
        }else{
            cout << "\tLua chon ko dung. Vui long nhap lai!" << endl;
        }
    }
}
};

int main (){
	sophuc *sp1 = new sophuc();
	sp1->nhap();
	sp1->Menu();
	delete sp1;
	return 0;
}

