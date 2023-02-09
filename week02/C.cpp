#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int x = 0;
    cin >> x; 
    while (x % 2 == 0) {
        x /= 2;
    }

    if (x == 1) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl; 
    }
    return 0;
}