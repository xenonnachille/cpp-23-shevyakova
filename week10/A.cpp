#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main() {
    long long int Fibsquare[4] = {1, 1, 4, 9}, N = 0;
    cin >> N;
    for (int i = 3; i < N + 1; ++i) {
        Fibsquare[i % 4] = 2 * Fibsquare[(i - 1) % 4] + 2 * Fibsquare[(i - 2) % 4] - Fibsquare[(i - 3) % 4]; 
    }
    cout << Fibsquare[N % 4] << endl;
    return 0;
}