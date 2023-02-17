#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 5
#endif

int main() {
    int array[N];
    for (int i = 0; i<N; ++i) {
        cin >> array[i]; 
    }
    int extra_num = array[N-1];

    for (int i = N-1; i>0; --i) {
        array[i] = array[i-1];
    }
    array[0] = extra_num;
    for (int i = 0; i<N; ++i) {
        cout << array[i] << ' '; 
    }
    return 0;
}