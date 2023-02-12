#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void is_prime(int n) {
    if (i % 2 == 0) {
        cout << "NO" << endl;
        return;
    } else {
        for (int i = 3; i < sqrt(n); i += 2) {
            if (n % i == 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int x = 0;
    cin >> x; 
    is_prime(x);
    return 0;
}
