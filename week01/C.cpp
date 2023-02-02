#include <iostream>
#include <cmath>

int factorial(int num) {
    int fact = 1;
    for (int i = 1; i < num + 1; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int number = 0;
    std::cin >> number;
    std::cout << factorial(number) << std::endl;
    return 0; 
}