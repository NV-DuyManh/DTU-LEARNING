#include <iostream>

using namespace std;

#define MAX 10

int n = 5;  
int MaTran[MAX][MAX] = { 
    {0, 1, 1, 1, 0}, 
    {1, 0, 0, 0, 1}, 
    {1, 0, 0, 1, 1}, 
    {1, 0, 1, 0, 1}, 
    {0, 1, 1, 1, 0}  
}; 

int DuongDi[MAX];  
bool DaXet[MAX];   

bool TimHamilton(int k) {
    if (k == n) {
        if (MaTran[DuongDi[k - 1]][DuongDi[0]] == 1) {
            cout << "Chu trinh Hamilton: ";
            for (int i = 0; i < n; i++) cout << DuongDi[i] + 1 << " -> ";
            cout << DuongDi[0] + 1 << endl;
            return true;
        }
        return false;
    }
    for (int v = 1; v < n; v++) {
        if (!DaXet[v] && MaTran[DuongDi[k - 1]][v] == 1) {
            DuongDi[k] = v;
            DaXet[v] = true;
            if (TimHamilton(k + 1)) return true;
            DaXet[v] = false;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < n; i++) DaXet[i] = false;
    DuongDi[0] = 0;
    DaXet[0] = true;
    
    if (!TimHamilton(1)) cout << "Khong co chu trinh Hamilton\n";
    
    return 0;
}

