#include<iostream>
#include<string>
using namespace std;

struct City {
    string name;
    float income;
    int population;
};

void nhap(City &tt) {
    cout << "Nhap ten thanh pho: ";
    cin.ignore();
    getline(cin, tt.name);
    cout << "Nhap tong thu nhap: ";
    cin >> tt.income;
    cout << "Nhap dan so: ";
    cin >> tt.population;
}

void xuat(City tt) {
    cout << "Ten thanh pho: " <<tt.name << endl;
    cout << "Tong thu nhap: " << tt.income << endl;
    cout << "Dan so: " << tt.population << endl;
}

int main() {
    int n;
    cout << "Nhap so luong thanh pho: ";
    cin >> n;
    City tp[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin thanh pho thu " << i + 1 << " la:" << endl;
        nhap(tp[i]);
    }
    cout << "Danh sach thanh pho:" << endl;
    for (int i = 0; i < n; i++) {
        xuat(tp[i]);
    }
    int maxtn = 0;
    int maxds = 0;
    for (int i = 1; i < n; i++) {
        if (tp[i].income > tp[maxtn].income) {
            maxtn = i;
        }
        if (tp[i].population > tp[maxds].population) {
            maxds = i;
        }
    }
    cout << "Thanh pho co tong thu nhap cao nhat la: " << tp[maxtn].name << endl;
    cout << "Thanh pho co dan so dong nhat la: " << tp[maxds].name << endl;
    return 0;
}

