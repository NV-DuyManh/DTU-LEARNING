#include<iostream>
#include<vector>
using namespace std;

class BOOK{
	protected:
		string bookD, publisher, entryDate ;
		float unitPrice ;
		int quantity;
	public:
		BOOK(){
		}
		BOOK(string bookD, string publisher,string entryDate,float unitPrice,int quantity){
			this->bookD = bookD;
			this->publisher = publisher;
			this->entryDate = entryDate;
			this->unitPrice = unitPrice;
			this->quantity = quantity;
		}
		~BOOK(){
		}
	
	string get_bookD(){
		return this->bookD;
	}
	string get_publisher(){
		return this->publisher;
	}
	string get_entryDate(){
		return this->entryDate;
	}
	float get_unitPrice(){
		return this->unitPrice;
	}
	int get_quantity(){
		return this->quantity;
	}
	
	void set_bookD(string bookD){
		this->bookD = bookD;
	}
	void set_publisher(string publisher){
		this->publisher = publisher;
	}
	void set_entryDate(string entryDate){
		this->entryDate =  entryDate;
	}
	void set_unitPrice(float unitPrice){
		this->unitPrice = unitPrice;
	}
	void set_quantity(int quantity){
		this->quantity = quantity;
	}
	
	virtual void Input(){
		fflush(stdin);
		cout <<"Nhap ten sach: ";
		getline(cin, this->bookD);
		cout <<"Nhap NXB: ";
		getline(cin, this->publisher);
		cout <<"Nhap ngay:  ";
		getline(cin, this->entryDate);
		cout <<"Nhap don gia:   ";
		cin>>this->unitPrice;
		cout <<"Nhap so luong: ";
		cin>>this->quantity;
	}
	virtual void Output(){
		cout<<"Ten sach  :"<<this->bookD  <<endl;
		cout<<"NXB :"<<this->publisher  <<endl;
		cout<<"Ngay   :"<<this->entryDate  <<endl;
		cout<<"Don gia  :"<<this->unitPrice  <<endl;
		cout<<"So luong  :"<<this->quantity  <<endl;
	}
	virtual float CalculateTotal () = 0;
};
class TEXTBOOK : public BOOK{
	private:
		string status ;
	public:
		TEXTBOOK(){
		}
		TEXTBOOK(string bookD, string publisher,string entryDate,float unitPrice,int quantity,string status):BOOK(){
			this->status = status;
		}
		~TEXTBOOK(){
		}
	string get_status(){
		return this->status;
	}
	void set_status(){
		this->status = status;
	}
	void Input(){
		BOOK::Input();
		fflush(stdin);
		cout <<"Nhap trang thai: ";
		getline (cin, this->status);
	}
	void Output(){
		BOOK::Output();
		cout <<"Trang thai: "<<this->status<<endl;
		cout <<"Thanh tien sach: "<<CalculateTotal ()<<endl;
	}
	float CalculateTotal (){
		if(this->status == "new"){
			return this->unitPrice *this->quantity;
		}else if(this->status == "old"){
			return this->unitPrice *this->quantity *50/100;
		}else{
			cout <<"Error!!";
		}
	}

};
class REFERENCEBOOK : public BOOK{
	private:
		float tax;
	public:
		REFERENCEBOOK(){
		}
		REFERENCEBOOK(string bookD, string publisher,string entryDate,float unitPrice,int quantity,string status, float tax):BOOK(){
			this->tax = tax;
		}
	float get_tax(){
		return this->tax;
	}
	void set_tax(float tax){
		this->tax = tax;
	}
	void Input(){
		BOOK::Input();
		cout <<"Nhap thue: ";
		cin>>this->tax;
	}
	void Output(){
		BOOK::Output();
		cout<<"Thue: "<<this->tax<<endl;
		cout<<"Thanh tien STK: "<<CalculateTotal ()<<endl;
	}
	float CalculateTotal (){
		return this->unitPrice *this->quantity + this->tax;
	}
};
class BOOKLIST{
	private:
		vector<BOOK*>ds;
	public:
		BOOKLIST(){
		}
		~BOOKLIST(){
			for(int i=0; i<ds.size(); i++){
				delete ds[i];
				ds.clear();
			}
			ds.clear();
		}
	void NhapDs(){
		while(true){
			cout<<"\t\tNhap tuy chon: "<<endl;
			cout<<"\t1.Nhap Textbook"<<endl;
			cout<<"\t2.Nhap sach tham khao"<<endl;
			cout<<"\t3.Thoat"<<endl;
			int luachon;
			cout<<"Nhap lua chon: ";
			cin>>luachon;
			if(luachon == 1){
				BOOK *tb = new TEXTBOOK();
				tb->Input();
				ds.push_back(tb);
			}else if(luachon == 2){
				BOOK *stk = new REFERENCEBOOK();
				stk->Input();
				ds.push_back(stk);
			}else if(luachon == 3){
				break;
			}else{
				cout<<" Lua chon ko dung, nhap lai!!"<<endl;
			}
		}
	}
	void XuatDs(){
		for(int i=0; i<ds.size();i++){
			cout<<"Thong tin sach thu: "<<i+1<<" la: "<<endl;
			ds[i]->Output();
		}
	}
	void Menu(){
		while(true){
			cout<<"\t\t===Menu==="<<endl;
			cout<<"\t\t1.Them ds"<<endl;
			cout<<"\t\t2.Cap nhat ds"<<endl;;
			cout<<"\t\t3.Tim sach"<<endl;
			cout<<"\t\t4.Tinh tong tien"<<endl;
			cout<<"\t\t5.Thoat"<<endl;
			int nhap;
			cout<<"Nhap lua chon: ";
			cin>>nhap;
			if(nhap == 1){
				NhapDs();
			}else if(nhap == 2){
				XuatDs();
			}else if(nhap == 3){
				tim();
			}else if(nhap == 4){
				cout <<"Tong tien sach la:"<<tong ();
			}else if(nhap == 5){
				break;
			}else{
				cout<<" Lua chon ko dung, nhap lai!!"<<endl;
		}
	}}
	void tim(){
		fflush(stdin);
		string sach;
		cout<<"Nhap sach can tim: ";
		getline(cin, sach);
		int b;
		for(int i=0;i<ds.size();i++){
			if(ds[i]->get_bookD() == sach){
				ds[i]->Output();
				b++;
			}else{
				cout<<"Khong co sach can tim!!";
			}
		}
	}
	float tong (){
		float tongtien =0;
		for(int i=0;i<ds.size();i++){
            tongtien+=ds[i]->CalculateTotal ();
		}
	}
};
int main(){
	BOOKLIST *a = new BOOKLIST();
	a->Menu();
	delete a;
	return 0;
}




