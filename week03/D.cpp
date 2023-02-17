#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 5
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
    
    for (int i = 0; i<N; ++i) {
        for (int j = 0; j<N-i-1; ++j) {
            if (array[j] < 0 and array[j+1] >= 0) {
                swap(array[j], array[j+1]);
            }
        }
    }

    for (int i = 0; i<N; ++i) {
        cout << array[i] << ' '; 
    }
    return 0;
}