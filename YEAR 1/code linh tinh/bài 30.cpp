//Bài 30: Cho so nguyen duong n. Kiem tra xem n có phai la so hoan thien hay khong 
#include <iostream>
using namespace std;
int main() {
 int n ,i;
 long S;
 do{ 
     cout << "Nhap n:";
     cin >> n;
     if (n<=0) {
         cout << "Sai dieu kien!";
     }
     }while(n <= 0);
    i = 1;
    S = 0;
    while(i < n)
    {
        if(n % i == 0)
        {
           S = S + i;
        }
            i++;
    }
    if(S == n) {
        cout<<("\nLa so hoan thien");
    }
    else {
        cout<<("\nSo nhap vao khong la so hoan thien");
    }
    return 0;
    }
