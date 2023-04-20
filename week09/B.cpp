#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int gsd(int a, int b) {
    if (a < b) {
        int a0 = a, b0 = b;
        a = b0, b = a0;
    }
    if (b == 0) {
        std::cout << a << '\n';
    }
    int rem = 1;
    rem = a % b;
    while (rem != 0) {
        a = b, b = rem;
        rem = a % b;
    }
    return b;
    }

void is_frac_norm(int& M, int& N) {
    int c = gsd(M, N);
    if (c != 1) {
        M /= c;
        N /= c;
    }
    return;
}

int main() {
    double m, n;
    int  M = 0, N = 1, i = 2;
    cin >> m >> n;

    while (1. / i > m / n) {
        i++;
    }
    M = M * i + N;
    N *= i;
    is_frac_norm(M, N);
    
    while ((1. * M) / N <= m / n) {
        if (M == int(m) and N == int(n)) {
            cout << i << endl;
            break;
        }  

        cout << i << ' ';
        i = 3;
        while ((1. * M) / N + 1. / i > m / n) {
            i++;
        }
        M = M * i + N;
        N *= i;
        is_frac_norm(M, N);
    }

    return 0;
}