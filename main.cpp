#include <iostream>
#include "complex.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Complex c1(3, 4);
    Complex c2;
    Complex c3(c1);

    std::cout << "Введите действительную и мнимую части для c2: ";
    std::cin >> c2;

    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";
    std::cout << "c3 (копия c1): ";
    c3.Show();

    std::cout << "c1 + c2 = " << (c1 + c2) << "\n";
    std::cout << "c1 - c2 = " << (c1 - c2) << "\n";
    std::cout << "c1 * c2 = " << (c1 * c2) << "\n";
    std::cout << "c1 / c2 = " << (c1 / c2) << "\n";

    c3 = c2;
    c3 += c1;
    std::cout << "После c3 = c2 и c3 += c1: " << c3 << "\n";

    std::cout << "++c1 = " << (++c1) << "\n";
    std::cout << "c1++ = " << (c1++) << " (после: " << c1 << ")\n";
    std::cout << "--c1 = " << (--c1) << "\n";
    std::cout << "c1-- = " << (c1--) << " (после: " << c1 << ")\n";

    std::cout << std::boolalpha;
    std::cout << "|c1| > |c2|:  " << (c1 > c2) << "\n";
    std::cout << "|c1| < |c2|:  " << (c1 < c2) << "\n";
    std::cout << "|c1| == |c2|: " << (c1 == c2) << "\n";
    std::cout << "|c1| != |c2|: " << (c1 != c2) << "\n";

    return 0;
}