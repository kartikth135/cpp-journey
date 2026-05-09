#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Operator overloading
    Complex operator+(const Complex& c) { return Complex(real + c.real, imag + c.imag); }
    Complex operator-(const Complex& c) { return Complex(real - c.real, imag - c.imag); }
    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }
    Complex operator/(const Complex& c) {
        double denom = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denom,
                       (imag * c.real - real * c.imag) / denom);
    }

    bool operator==(const Complex& c) { return real == c.real && imag == c.imag; }

    // Magnitude
    double magnitude() { return sqrt(real * real + imag * imag); }

    // Conjugate
    Complex conjugate() { return Complex(real, -imag); }

    // Display
    void display() {
        if (imag >= 0) cout << real << " + " << imag << "i";
        else cout << real << " - " << -imag << "i";
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imag >= 0) os << c.real << " + " << c.imag << "i";
        else os << c.real << " - " << -c.imag << "i";
        return os;
    }
};

int main() {
    Complex a(3, 4), b(1, -2);

    cout << "A = " << a << "\n";
    cout << "B = " << b << "\n\n";

    cout << "A + B = " << a + b << "\n";
    cout << "A - B = " << a - b << "\n";
    cout << "A * B = " << a * b << "\n";
    cout << "A / B = " << a / b << "\n\n";

    cout << "Magnitude of A = " << a.magnitude() << "\n";
    cout << "Conjugate of A = " << a.conjugate() << "\n";

    return 0;
}