#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void is_palindrom(int n) {
    long long int helping_num = n, reversed_num = 0;
    while (helping_num > 0) {
        reversed_num = 10 * reversed_num + helping_num % 10;
        helping_num /= 10;
    }
    
    if (n == reversed_num) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}

int main() {
    int n = 0;
    cin >> n;
    is_palindrom(n);
    return 0;
}
