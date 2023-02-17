#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 3
#endif

int main() {
    int array1[N];
    int array2[N];
    int M = 2*N;
    int array[M];
    for (int i = 0; i<N; ++i) {
        cin >> array1[i]; 
    }
    for (int i = 0; i<N; ++i) {
        cin >> array2[i]; 
    }
    int j = 0, k = 0, i = 0;
    while(j<N and k<N and i<M) {
        if (array1[j] < array2[k]) {
            array[i] = array1[j];
            ++j;
            i++;
        } else {
            array[i] = array2[k];
            ++k;
            i++;
        }
    }
    while (j<N) {
        array[k+j] = array1[j];
        j++;
    }
    while (k<N) {
        array[k+j] = array2[k];
        k++;
    }

    for (int i = 0; i<M; ++i) {
        cout << array[i] << ' '; 
    }
    return 0;
}