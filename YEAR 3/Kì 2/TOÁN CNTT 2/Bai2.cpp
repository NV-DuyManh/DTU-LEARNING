#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void InHePhuongTrinh(double maTran[4][5]) {
    cout << "--- He phuong trinh can giai ---\n";
    for (int i = 0; i < 4; i++) {
        cout << maTran[i][0] << "x ";
        
        if (maTran[i][1] >= 0) cout << "+ " << maTran[i][1] << "y ";
        else cout << "- " << abs(maTran[i][1]) << "y ";
        
        if (maTran[i][2] >= 0) cout << "+ " << maTran[i][2] << "z ";
        else cout << "- " << abs(maTran[i][2]) << "z ";
        
        if (maTran[i][3] >= 0) cout << "+ " << maTran[i][3] << "t ";
        else cout << "- " << abs(maTran[i][3]) << "t ";
        
        cout << "= " << maTran[i][4] << "\n";
    }
    cout << "\n";
}

void InMaTran(double maTran[4][5], int buoc) {
    cout << "--- Ma tran sau buoc " << buoc << " ---\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(8) << maTran[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void GiaiHePhuongTrinh(double maTran[4][5], double nghiem[4], double &dinhThuc) {
    int n = 4;
    dinhThuc = 1.0;

    InMaTran(maTran, 0);

    for (int i = 0; i < n; i++) {
        if (maTran[i][i] == 0) {
            dinhThuc = 0;
            return;
        }

        dinhThuc *= maTran[i][i];
        double chot = maTran[i][i];

        for (int j = i; j <= n; j++) {
            maTran[i][j] /= chot;
        }

        for (int k = i + 1; k < n; k++) {
            double heSo = maTran[k][i];
            for (int j = i; j <= n; j++) {
                maTran[k][j] -= heSo * maTran[i][j];
            }
        }
        InMaTran(maTran, i + 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        nghiem[i] = maTran[i][n];
        for (int j = i + 1; j < n; j++) {
            nghiem[i] -= maTran[i][j] * nghiem[j];
        }
    }
}

int main() {
    double ngaySinh = 20.00;
    double thangSinh = 9.00;

    double maTran[4][5] = {
        {1.00, 1.00, -1.00, 3.00, ngaySinh},
        {2.00, -1.00, 1.00, -1.00, thangSinh},
        {3.00, 1.00, -2.00, 1.00, ngaySinh - thangSinh},
        {2.00, 1.00, 2.00, 3.00, ngaySinh + thangSinh}
    };

    double nghiem[4] = {0.00, 0.00, 0.00, 0.00};
    double dinhThuc = 0.00;

    cout << fixed << setprecision(2);
    
    InHePhuongTrinh(maTran);

    GiaiHePhuongTrinh(maTran, nghiem, dinhThuc);

    cout << "================================\n";
    if (dinhThuc != 0) {
        cout << "Ket qua he phuong trinh:\n";
        cout << "x = " << nghiem[0] << "\n";
        cout << "y = " << nghiem[1] << "\n";
        cout << "z = " << nghiem[2] << "\n";
        cout << "t = " << nghiem[3] << "\n";
        cout << "Dinh thuc det(A) = " << dinhThuc << "\n";
    } else {
        cout << "Dinh thuc det(A) = 0.00. He phuong trinh vo nghiem hoac co vo so nghiem.\n";
    }

    return 0;
}
