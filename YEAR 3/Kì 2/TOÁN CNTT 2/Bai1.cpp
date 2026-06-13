#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double a = 20.0;
const double b = 9.0;
const double saiSo = 1e-5;
const int soLanLapToiDa = 100;

double ham(double x) {
    return x * x * x + a * x + b;
}

double daoHam(double x) {
    return 3 * x * x + a;
}

void chiaDoi(double trai, double phai) {
    cout << "\n--- PHUONG PHAP CHIA DOI ---\n";

    if (ham(trai) * ham(phai) >= 0) return;

    double giua;
    for (int lan = 1; lan <= 5; lan++) {
        giua = (trai + phai) / 2;
        cout << "Lan " << lan << ": x = " << fixed << setprecision(5) << giua
             << " | f(x) = " << ham(giua) << endl;

        if (ham(trai) * ham(giua) < 0)
            phai = giua;
        else
            trai = giua;
    }

    cout << "Nghiem x5 = " << giua << endl;
}

void dayCung(double trai, double phai) {
    cout << "\n--- PHUONG PHAP DAY CUNG ---\n";

    if (ham(trai) * ham(phai) >= 0) return;

    double x = trai, xCu;
    int lan = 0;

    do {
        xCu = x;
        x = (trai * ham(phai) - phai * ham(trai)) / (ham(phai) - ham(trai));

        if (ham(trai) * ham(x) < 0)
            phai = x;
        else
            trai = x;

        lan++;
    } while (abs(x - xCu) > saiSo && lan < soLanLapToiDa);

    cout << "Hoi tu sau " << lan << " lan lap\n";
    cout << "Nghiem = " << fixed << setprecision(5) << x << endl;
}

void tiepTuyen(double x) {
    cout << "\n--- PHUONG PHAP TIEP TUYEN ---\n";

    int lan = 0;
    double xMoi;

    do {
        xMoi = x - ham(x) / daoHam(x);
        lan++;
        if (abs(xMoi - x) < saiSo) break;
        x = xMoi;
    } while (lan < soLanLapToiDa);

    cout << "Hoi tu sau " << lan << " lan lap\n";
    cout << "Nghiem = " << fixed << setprecision(5) << xMoi << endl;
}

int main() {
    cout << "Phuong trinh: x^3 + " << a << "x + " << b << " = 0\n";

    double trai = -5.0;
    double phai = 0.0;

    chiaDoi(trai, phai);
    dayCung(trai, phai);
    tiepTuyen(-1.0);

    return 0;
}

