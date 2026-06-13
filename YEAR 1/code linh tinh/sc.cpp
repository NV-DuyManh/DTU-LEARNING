#include <iostream>
#include <fstream>
using namespace std;
int main(){
	int n;
	cin>>n;
	ofstream fo("output.txt");
	for( int i=1; i<=n;i++){
		fo <<i << endl;
	}
	fo.close();
}
