#include <iostream>
using namespace std;

class Sophuc {
private:
    float a, b;

public:
    Sophuc() {
        this->a = 0;
        this->b = 0;
    }

    Sophuc(float a, float b) {
        this->a = a;
        this->b = b;
    }

    
    Sophuc cong(Sophuc other) {
        return Sophuc(a + other.a, b + other.b);
    }
    Sophuc tru(Sophuc other) {
        return Sophuc(a - other.a, b - other.b);
    }

    Sophuc nhan(Sophuc other) {
        float real = a * other.a - b * other.b;
        float imag = a * other.b + b * other.a;
        return Sophuc(real, imag);
    }

    Sophuc chia(Sophuc other) {
        float denominator = other.a * other.a + other.b * other.b;
        float real = (a * other.a + b * other.b) / denominator;
        float imag = (b * other.a - a * other.b) / denominator;
        return Sophuc(real, imag);
    }

    void xuat() {
        cout << "Ket qua so phuc can tim la: " << a << " + " << b << "i" << endl;
    }
};

int main() {
    Sophuc sp1(2, 3);
    Sophuc sp2(-7, 5);

    Sophuc tong = sp1.cong(sp2);
    Sophuc hieu = sp1.tru(sp2);
    Sophuc tich = sp1.nhan(sp2);
    Sophuc thuong = sp1.chia(sp2);

    cout << "Tong: ";
    tong.xuat();

    cout << "Hieu: ";
    hieu.xuat();

    cout << "Tich: ";
    tich.xuat();

    cout << "Thuong: ";
    thuong.xuat();

    return 0;
}

