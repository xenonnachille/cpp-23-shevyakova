#include <iostream>
#include <cmath>

int gsd(int a, int b) {
    if (a < b) {
        int a0 = a, b0 = b;
        a = b0, b = a0;
    }
    if (b == 0) {
        std::cout << a << '\n';
    }
    int rem = 1, factor = 0;
    rem = a % b;
    factor = (a - rem)/b;
    while (rem != 0) {
        a = b, b = rem;
        rem = a % b;
    }
    return b;
    }

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a*b/gsd(a, b) << std::endl;
    return 0;
}