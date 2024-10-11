
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
    private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0);
        double getReal() const;
    double getImag() const;


    void setReal(double r);
    void setImag(double i);
    
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};
#endif // COMPLEX_H