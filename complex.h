#pragma once

#include <iostream>

class Complex {
private:
    double real_;
    double image_;

public:
    Complex();
    Complex(double real, double image);
    Complex(const Complex& other);
    ~Complex();

    void Show() const;
    Complex& operator=(const Complex& other);
    Complex& operator+=(const Complex& other);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};
