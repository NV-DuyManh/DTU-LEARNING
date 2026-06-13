#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Diem{
	long long x,y;
};
double khoangcach(Diem a, Diem b){
	return sqrt((a.x - b.x) * (a.x - b.x)+(a.y - b.y) * (a.y-b.y));
}
int n;
vector <Diem> d;
void sol1() {
    int v1 = 0, v2 = 1;
    double dmin = khoangcach(d[v1], d[v2]);
    for (int i = 0; i < d.size()-1; i++) {
        for (int j = i+1; j < d.size(); j++) {
            double kc = khoangcach(d[i], d[j]);
            if (kc < dmin) { 
                dmin = kc; 
                v1 = i; 
                v2 = j; 
            }
            else if (kc == dmin) {
                if (d[i].x + d[j].x < d[v1].x + d[v2].x) { 
                    v1 = i; 
                    v2 = j; 
                }
            }
        }
    }
    cout << fixed << setprecision(4) << dmin << endl;
    if (d[v1].x < d[v2].x) {
        cout << d[v1].x << " " << d[v1].y << " " << d[v2].x << " " << d[v2].y << endl;
    }
    else {
      
            if (d[v1].x > d[v2].x)
                cout << d[v2].x << " " << d[v2].y << " " << d[v1].x << " " << d[v1].y << endl;
            else
                if(d[v1].y <d[v2].y)
                cout << d[v1].x << " " << d[v1].y << " " << d[v2].x << " " << d[v2].y << endl;
                else
                cout << d[v2].x << " " << d[v2].y << " " << d[v1].x << " " << d[v1].y << endl;
          
       
    }
}
int main(){
	cin>>n;
	d.resize(n);
	for(int i=0;i<n;i++){
		cin>>d[i].x >>d[i].y;
	}
	sol1();
	return 0;
}
