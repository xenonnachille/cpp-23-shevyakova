#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 2
#endif

#ifndef M
#define M 4
#endif


void sort2d(int (&array)[N][M]) {
    int str_array[N*M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            str_array[j+M*i] = array[i][j];
        }
    }
    
    for (int i = 0; i<N*M; ++i) {
        cout << str_array[i] << ' ';
    }
    cout << '\n';

    for (int j = 0; j < N*M; j++) {
        int num = str_array[j];
        int k = j - 1;
        while (k >= 0 and num < str_array[k]) {
            str_array[k + 1] = str_array[k];
            k--; 
            str_array[k + 1] = num;
        }
        }

    for (int i = 0; i<N*M; ++i) {
    cout << str_array[i] << ' ';
    }
    cout << '\n';

    for (int i = 0; i<N*M; i++) {
        array[i/M][i%M] = str_array[i];
    }
    return; 
}

int main() {
    int array[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> array[i][j]; 
        }
    }   
    sort2d(array);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << array[i][j] << ' '; 
        }
        cout << '\n';
    }  
    return 0;
}