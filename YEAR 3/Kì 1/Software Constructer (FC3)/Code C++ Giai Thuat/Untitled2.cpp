#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>; //typedef vector<int> vi;
void sinh(int n, vi &a)
{
	a.resize(n); for(int i=0; i<n; i++) a[i]= rand()%1001;
}
void in(vi a){
	cout<<"\n Noi dung day:"; 
	for(auto x:a) cout<<x<<" ";
}
vi qs(vi &a) {
	if(a.size()>1)
	{
		vi dl, dr, dm;
		int p = a[a.size()/2];
		for(int x : a)
			if(x<p) dl.push_back(x);
			else if(x>p)  dr.push_back(x);
				else dm.push_back(x);
		dl= qs(dl); dr= qs(dr);
		a.clear(); 
		a.insert(a.end(), dl.begin(), dl.end());	
		a.insert(a.end(), dm.begin(), dm.end());
		a.insert(a.end(), dr.begin(), dr.end());	
		dl.clear(); dm.clear();dr.clear();
	}
    return a; 
}

int main() {
    int n = 10;   //cin>>n;
    vi a(n);sinh(n, a); in(a);
    vi res = qs(a); in(res);
    cout<<"\n XONG!";
}
