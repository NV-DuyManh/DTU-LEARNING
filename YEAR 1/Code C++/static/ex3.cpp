#include <iostream>
using namespace std;

class Fraction {
    private:
        float numerator, denominator;
    public:
        Fraction(){
        	this->numerator = 0;
        	this->denominator = 1;
		} 
        Fraction(float numerator, float denominator){
        	this->numerator = numerator;
			this->denominator = denominator;
		}
		Fraction(const Fraction &ps_other){
			this->numerator = ps_other.numerator;
			this->denominator = ps_other.denominator;
		}
		void operator = (const Fraction &ps_other){
			this->numerator = ps_other.numerator;
			this->denominator = ps_other.denominator;
		}
        ~Fraction(){
		}
		float get_numerator(){
			return this->numerator;
		}
		float get_denominator(){
			return this->denominator;
		}
		void set_numerator(float numerator){
			this->numerator = numerator;
		}
		void set_denominator(float denominator){
			this->denominator = denominator;
		}

        Fraction operator+(const Fraction &f) {
            float num = this->numerator * f.denominator + this->denominator * f.numerator;
            float den = this->denominator * f.denominator;
            return Fraction(num, den);
        }

        Fraction operator-(const Fraction &f) {
            float num = this->numerator * f.denominator - this->denominator * f.numerator;
            float den = this->denominator * f.denominator;
            return Fraction(num, den);
        }

        Fraction operator*(const Fraction &f) {
            float num = this->numerator * f.numerator;
            float den = this->denominator * f.denominator;
            return Fraction(num, den);
        }
        Fraction operator/(const Fraction &f) {
            float num = this->numerator * f.denominator;
            float den = this->denominator * f.numerator;
            return Fraction(num, den);
        }

        friend istream& operator>>(istream &is, Fraction &f) {
            cout << "Nhap tu: ";
            is >> f.numerator;
            cout << "Nhap mau: ";
            is >> f.denominator;
            return is;
        }

        friend ostream& operator<<(ostream &os, const Fraction &f) {
            os << f.numerator << "/" << f.denominator;
            return os;
        }
};

int main() {
    Fraction p1;
    cin >> p1;
    cout <<"Phan so thu 1: "<< p1 << endl;

    Fraction p2;
    cin >> p2;
    cout <<"Phan so thu 1: "<< p2 << endl;

    Fraction p3 = p1 + p2;
    cout <<"Cong: "<<p1 <<" + "<< p2<<" = "<< p3 << endl;
    
    Fraction p4 = p1 - p2;
    cout <<"Tru : "<<p1 <<" - "<< p2<<" = "<< p4 << endl;
    
    Fraction p5 = p1 * p2;
    cout <<"Nhan: "<<p1 <<" * "<< p2<<" = "<< p5 << endl;
    
    Fraction p6 = p1 / p2;
    cout <<"Chia: "<<p1 <<" / "<< p2<<" = "<< p6 << endl;

    return 0;
}

