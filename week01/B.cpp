#include <iostream>
#include <cmath>

int main() {
    float a = 0., b = 0., c = 0.;
    float x1 = 0., x2 = 0.;
    std::cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c != 0) {
                std::cout << '\n' << std::endl;
            } else if (c == 0) {
                std::cout << "ALL REAL NUMBERS" << std::endl;
            }
        } else if (c == 0) {
            x1 = 0;
            std::cout << x1 << std::endl;
        } else if (c != 0) {
        x1 = -c/b;
        std::cout << x1 << std::endl;
        }
    } else {
        if (a < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        }
    int d = b*b - 4*a*c;
    if (d < 0) {
        std::cout<< '\n' << std::endl;
    } else if (d == 0) {
        x1 = -b/(2*a);
        if (b == 0) {
            x1 = 0;
        }
        std::cout << x1 << std::endl;
    } else {
        x1 = (-b - sqrt(d))/(2*a);
        x2 = (-b + sqrt(d))/(2*a);
        std::cout << x1 << ' ' << x2 << std::endl;
    }
    }
    return 0; 
}