#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main() {
    int L = 0;
    int price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int length[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int how_expensive[10];

    for (int i = 0; i < 10; i++) {
        how_expensive[i] = static_cast<float>(price[i]/length[i]);
    }

    

    return 0;
}