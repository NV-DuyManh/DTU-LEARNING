#include <iostream>
using namespace std;

//tinh da hinh


class Nhanvat{ // lop truu tuong (anstract class)
	public:
		virtual void Dichuyen(){  //phuong thuc ao
			cout  <<"Nhan vat dang di chuyen..."<<endl;
		}
//		void Dichuyen(string caigido){
//			cout <<"Nhan vat di chuyen bang "<< caigido;
//		}

    virtual void tancong() = 0; //phuong thuc thuan ao
    	
	
};

class Nhanvatbt : public Nhanvat{
	public: 
	void Dichuyen(){
		cout <<"Chay bo"<<endl;
	}
	void tancong(){
		cout <<"Danh bang tay "<<endl;
	}
};

class Nhanvatcb : public Nhanvat{
	public:
	void Dichuyen(){
    	cout <<"Cuoi ngua"<<endl;
	}
	void naptien(){
		cout <<"Nap tien cho cai bang....";
	}
	void tancong(){
	cout <<"giang lam"<<endl;
}
};

void Dichuyen1(Nhanvat *nhanvat){
	nhanvat->Dichuyen();
	if(dynamic_cast<Nhanvatcb*>(nhanvat) !=NULL){ //Kiem tra co phai cai bang ko
		Nhanvatcb *new_nvcb = dynamic_cast<Nhanvatcb*>(nhanvat); //dowcasting
		new_nvcb->naptien();
	}
}
int main(){
//	Nhanvat *nv = new Nhanvat();
	Nhanvat *nvbt = new Nhanvatbt();
	Nhanvat *nvcb = new Nhanvatcb();			
	
//	nvbt = new Nhanvatcb();
//	nvbt->Dichuyen();
//	nv->Dichuyen();
//	nvbt->Dichuyen();
//	nvcb->Dichuyen();
//    Dichuyen1(nvbt);
//    Dichuyen1(nvcb);
	return 0;
}
