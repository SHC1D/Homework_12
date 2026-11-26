#include "complex.h"
#include <sstream>
#include <cmath>


Complex::Complex() : real_(0.0), image_(0.0) {}
Complex::Complex(double real, double image) : real_(real), image_(image) {}
Complex::Complex(const Complex& other) : real_(other.real_), image_(other.image_) {}
Complex::~Complex() {}


void Complex::Show() const {
    std::ostringstream oss;
    if (real_ != 0 || image_ == 0) {
        oss << real_;
    }
    if (image_ != 0) {
        if (image_ > 0 && real_ != 0) {
            oss << "+";
        }
        oss << image_ << "i";
    }
    std::cout << oss.str() << "\n";
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real_ = other.real_;
        image_ = other.image_;
    }
    return *this;
}

Complex& Complex::operator+=(const Complex& other) {
    real_ += other.real_;
    image_ += other.image_;
    return *this;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real_ + other.real_, image_ + other.image_);
}
Complex Complex::operator-(const Complex& other) const {
    return Complex(real_ - other.real_, image_ - other.image_);
}


Complex Complex::operator*(const Complex& other) const {
    return Complex(
        real_ * other.real_ - image_ * other.image_,
        real_ * other.image_ + image_ * other.real_
    );
}


Complex Complex::operator/(const Complex& other) const {
    double denom = other.real_ * other.real_ + other.image_ * other.image_;
    if (denom == 0.0) {
        std::cerr << "Ошибка: деление на ноль!\n";
        return Complex();
    }
    return Complex(
        (real_ * other.real_ + image_ * other.image_) / denom,
        (image_ * other.real_ - real_ * other.image_) / denom
    );
}

Complex& Complex::operator++() {
    ++real_;
    ++image_;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++(*this);
    return temp;
}

Complex& Complex::operator--() {
    --real_;
    --image_;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    --(*this);
    return temp;
}
bool Complex::operator>(const Complex& other) const {
    return std::hypot(real_, image_) > std::hypot(other.real_, other.image_);
}

bool Complex::operator<(const Complex& other) const {
    return std::hypot(real_, image_) < std::hypot(other.real_, other.image_);
}

bool Complex::operator==(const Complex& other) const {
    return std::abs(std::hypot(real_, image_) - std::hypot(other.real_, other.image_)) < 1e-9;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}


std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real_;
    if (c.image_ >= 0) {
        os << "+" << c.image_ << "*i";
    }
    else {
        os << c.image_ << "*i";
    }
    return os;
}


std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.real_ >> c.image_;
    return is;
}