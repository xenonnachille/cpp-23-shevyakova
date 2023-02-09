#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int a = 0;
    cin >> a;
    if (a % 4 == 0) {
        if (a % 400 == 0) {
            cout << "YES" << endl;
        } else if (a % 100 == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}