#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int x = 0;
    int count = 0;

    cin >> x;
    if (x % 2 == 0) {
        count++;
    }
    while (x != 0) {
        cin >> x;
        if (x % 2 == 0) {
        count++;
        }
    }
    cout << count - 1 << endl;
    return 0;
}