#include <iostream>
#include <cmath>

int main() {
    int a = 0, b = 0, c = 0, d = 0;
    float x1 = 0., x2 = 0.;
    std::cin >> a >> b >> c;
    d = b*b - 4*a*c;
    
    if (a<0) {
        a *= -1;
        b *= -1;
        c *= -1;
    }

    if ((a == 0 and b == 0) or d < 0) {
            std::cout << '\n' << std::endl;
    } else if (a == 0) {
        x1 = -c/b;
        std::cout << x1 << std::endl;
    } else if (d == 0) {
        x1 = -b/(2*a);
        std::cout << x1 << std::endl;
    } else {
        x1 = (-b - sqrt(d))/(2*a);
        x2 = (-b + sqrt(d))/(2*a);
        std::cout << x1 << ' ' << x2 << std::endl;
    }
    return 0; 
}