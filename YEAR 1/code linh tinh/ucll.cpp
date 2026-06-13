#include <iostream>
using namespace std;
 
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {

    int num1, num2;
   cout <<"enter number 1: ";
   cin >> num1;
    
   cout <<"emter number 2: ";
   cin >> num2;


    int gcdResult = gcd(num1, num2);

 
    std::cout << "Greatest Common divisor (GCD) " << num1 << " and " << num2 << " is: " << gcdResult << std::endl;

    return 0;
}

