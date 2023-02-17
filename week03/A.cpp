#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 3
#endif

void swap(int& lha, int& rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

int main() {
    int array[N];
    for (int i = 0; i<N; ++i) {
        cin >> array[i]; 
    }

    for (int i = 0; i<N/2; ++i) {
        swap(array[i], array[N-1-i]);
    }

    for (int i = 0; i<N; ++i) {
        cout << array[i] << ' '; 
    }
    return 0;
}