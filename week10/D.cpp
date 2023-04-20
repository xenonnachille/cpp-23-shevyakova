#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main() {
    long long int steps[4] = {1, 2, 4, 7}, N = 0;
    cin >> N;
    for (int i = 3; i < N; ++i) {
        steps[i % 4] = steps[(i - 1) % 4] + steps[(i - 2) % 4] + steps[(i - 3) % 4]; 
    }
    cout << steps[(N - 1) % 4] << endl;
    return 0;
}