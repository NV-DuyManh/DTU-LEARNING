//Bài 31: Cho so nguyen duong n. Kiem tra xem n có phai là so nguyen to hay khong 
#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cout<<("Nhap n :");
    cin>>n;
    if(n < 2){
        cout<<("\nkhong phai so nguyen to");
        return 0;
    }
    int count = 0;
    for(int i = 2; i <= sqrt(n);i++){
        if(n % i == 0){
            count++;
        }
    }
    if(count == 0){
        cout<<("\n la so nguyen to");
    }else{
        cout<<("\nkhong phai so nguyen to");
    }
    return 0;
}
