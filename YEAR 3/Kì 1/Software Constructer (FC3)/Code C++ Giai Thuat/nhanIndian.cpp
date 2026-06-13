#include<bits/stdc++.h>
using namespace std;

string nhan2(string S){
	if(S=="0")return "0";
	else{
		int nho=0;
		string kq="";
		for(int i=S.length()-1;i>=0;i--){
			int so=(S[i]-'0')*2+nho;
			if(so>9)nho=1;else nho=0;
			kq=char(so%10+'0')+kq;
		}if(nho>0)kq="1"+kq;
		return kq;
		
	}
}
string chia2(string S){
	if(S=="0")return "0";
	else{
    string kq="";
    int du=0;
    for(int i=0;i<S.length();i++){
        int so = du*10 + (S[i]-'0'); 
        du = so%2;
        kq=char('0'+so/2)+kq;
       
    }
        return kq;
    }
}
int lhk(string s){
	if(s.length()>1|| s[0]!='0')return 1;
	else return 0;
}
int le(string s){
	return (s[s.length()-1]-'0')%2;
}
string nhanAD( string a, string b) {
	if(a=="0"||b=="0")
	return "0";
	else {
		string s="";
		while(lhk(bl)) {
			if(le(b))
			s=cong(s,a);
			b = chia2(b);
			if(thk(b))
			a=nhan2(a);
		}
		return S;
	}
}
int main() {

    string a;
    cin >> a;
    cout << nhan2(a);
    cout<<endl;
    cout << chia2(a);
    return 0;
    }

