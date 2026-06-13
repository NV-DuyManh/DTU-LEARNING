#include<iostream>
using namespace std;

void Nhap_mang(int arr[],int n){
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
}

void Xuat_mang(int arr[],int n){
	for (int i=0;i<n;i++){
		cout <<"arr[" <<i <<"] = " <<arr[i] << endl;
	}
}

int Tong(int arr[],int n){
	int Sum=0;
	for (int i=0;i<n;i++){
		int count=0;
		for(int j=2;j<=arr[i]/2;j++){
			if(arr[i]%j==0){
				count =1;
				break;
			}
		}
		if(count==0){
			Sum+=arr[i];
		}
	}
	return Sum;
}

void Kiem_tra(int x,int arr[],int n){
	int count =0;
	for (int i=0;i<n;i++){
		if(x==arr[i]){
			cout << x <<" o vi tri so :" << i+1;
				count++;
			}
		
		}
		if(count==0){
		cout <<"Khong tim thay " <<x <<" trong mang!";
	}	
}
	

int main () {
	int n;
	cout <<"Nhap kich thuoc cua mang : ";
	cin >> n;
	int arr1[n];
	
	cout <<"Nhap mang : " <<endl;
	Nhap_mang(arr1,n); cout <<endl;
	
	cout <<"Xuat mang : " <<endl;
	Xuat_mang(arr1,n); cout <<endl;
	
	cout <<"Tong cac so nguyen to = " << Tong(arr1,n);
	
	int x;
	cout <<endl <<"Nhap x = "; cin >> x;
	Kiem_tra(x,arr1,n);
	
	return 0;
}
