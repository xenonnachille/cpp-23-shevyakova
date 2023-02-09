#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int fibonacci(int i) {
    int ans = 0;
    if ((i == 0) || (i == 1)) {
        ans = 1;
    } else {
        ans = fibonacci(i - 1) + fibonacci(i - 2);
    }
    return ans;
}

int main() {
    int i = 0;
    cin >> i;
    cout << fibonacci(i) << endl;
    return 0;
}