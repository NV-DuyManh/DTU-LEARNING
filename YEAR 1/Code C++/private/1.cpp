#include <iostream>
using namespace std;

struct city {
	string name;
	float income;
	int population;
};

void nhap1(city &tp,int n){
	for (int i=-;i<=n;i++){
	
	fflush (stdin);
	cout <<"nhap ten thanh pho: ";
	cin >> tp.name;
	cout <<"nhap thu nhap: ";
	cin >> tp.income;
	cout <<"nhap so dan: ";
	cin>> tp.population;
	}
}


void xuat (city tp){
	cout<<"cac thanh pho da nhap la: "<< tp.name <<", ";
	cout <<"thanh pho co tong thu nhap cao nhat la: ";
	cout <<"thanh pho dong dan nhat la: ";
	
}

void nhap_ds(city ds[], int n){
	for (int i=0;i<=n;i++){
		nhap1(ds[i]);
}}
int main (){
	city n;
	nhap1(n);
	
	
	return 0;
}
