#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 3
#endif

int trace(int (&array)[N*N]) {
    int trace = 0;
    for (int i = 0; i<N*N; i += N+1) {
        trace += array[i];
    }
    return trace;
}

int main() {
    int array[N*N];
    for (int i = 0; i < N*N; i++) {
        cin >> array[i];
    }
    cout << trace(array) << '\n';
    return 0;
}