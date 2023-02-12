#include <iostream>

using std::cout;
using std::cin;
using std::endl;

long long int recursive_power(int base, int power) {
    long long int ans = base;
    if (power == 0) {
        return 1;
    } else {
        ans = base * recursive_power(base, power - 1);
        return ans;
    }
}

int main() {
    int base = 0, power = 0;
    cin >> base >> power;
    cout << recursive_power(base, power) << endl;
    return 0;
}
