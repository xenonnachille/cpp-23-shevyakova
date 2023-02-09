#include <iostream>

using std::cout;
using std::cin;
using std::endl;

long long int recursive_factorial(int n) {
    long long int ans = 1;
    if (n == 0) {
        return 1;
    }
    ans = n * recursive_factorial(n-1);
    return ans;
    
}

int main() {
    int i = 0;
    cin >> i;
    cout << recursive_factorial(i) << endl;
    
    return 0;
}