#include "assignment3.h"
#include <cmath>  // For sqrt function

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}
double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

// Setters
void Complex::setReal(double r) {
    real = r;
}

void Complex::setImag(double i) {
    imag = i;
}
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.getReal();
    if (c.getImag() >= 0)
        os << " + " << c.getImag() << "i";
    else
        os << " - " << -c.getImag() << "i";
    return os;
}