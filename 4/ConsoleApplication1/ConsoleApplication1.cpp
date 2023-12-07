#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber {
    double real, imag;

public:
    ComplexNumber(double real, double imag) : real(real), imag(imag) {}

    double modulus() const {
        return sqrt(real * real + imag * imag);
    }

    double argument() const {
        if (imag == 0) {
            return atan2(real, imag);
        }
        else {
            return atan2(imag, real);
        }
    }

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    ComplexNumber operator/(const ComplexNumber& other) const {
        if (other.modulus() == 0) {
            throw runtime_error("Деление на ноль");
        }
        return ComplexNumber((real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag),
            (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag));
    }

    void print() const {
        if (imag == 0) {
            cout << real;
        }
        else if (real == 0) {
            cout << imag << "i";
        }
        else {
            cout << real << " + " << imag << "i";
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    ComplexNumber a(1, 2);
    ComplexNumber b(3, 4);
    ComplexNumber c(5, -3);
    ComplexNumber d(7, 8);

    cout << "a = ";
    a.print();
    cout << endl;

    cout << "b = ";
    b.print();
    cout << endl;

    cout << "c = ";
    c.print();
    cout << endl;

    cout << "d = ";
    d.print();
    cout << endl;

    ComplexNumber R = (b + a - (b * (c / ComplexNumber(5, 0)))) / d;

    cout << "Результат: R = ";
    R.print();
    cout << endl;

    return 0;
}