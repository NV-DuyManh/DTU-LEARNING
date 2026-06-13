#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TH {
    vector<int> a;
public:
    friend istream &operator>>(istream &is, TH &b) {
        int size, element;
        cout << "Nhap so luong phan tu: ";
        is >> size;
        b.a.clear();
        cout << "Nhap cac phan tu: ";
        for (int i = 0; i < size; i++) {
            is >> element;
            b.a.push_back(element);
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, TH b) {
        os << "{";
        for (size_t i = 0; i < b.a.size(); i++) {
            os << b.a[i];
            if (i < b.a.size() - 1) os << ", ";
        }
        os << "}";
        return os;
    }

    TH operator+(TH b) {
        TH t;
        set_union(this->a.begin(), this->a.end(), b.a.begin(), b.a.end(), back_inserter(t.a));
        return t;
    }

    TH operator*(TH b) {
        TH t;
        set_intersection(this->a.begin(), this->a.end(), b.a.begin(), b.a.end(), back_inserter(t.a));
        return t;
    }

    TH operator-(TH b) {
        TH t;
        set_difference(this->a.begin(), this->a.end(), b.a.begin(), b.a.end(), back_inserter(t.a));
        return t;
    }
};

int main() {
    TH a, b, c;

    cout << "Nhap tap hop a:"<<endl; 
	cin >> a;
    cout << "Nhap tap hop b:"<<endl; 
	cin >> b;

    cout << "Tap hop a: " << a << endl;
    cout << "Tap hop b: " << b << endl;

    c = a + b;
    cout << "Hop cua a va b: " << c << endl;

    c = a * b;
    cout << "Giao cua a va b: " << c << endl;

    c = a - b;
    cout << "Hieu cua a tru b: " << c << endl;

    c = b - a;
    cout << "Hieu cua b tru a: " << c << endl;

    return 0;
}

