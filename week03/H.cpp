#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 2
#endif

#ifndef M
#define M 3
#endif

int main() {
    int array[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> array[i][j]; 
        }
    }   

    /*int array_t[M][N];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            array_t[i][j] = array[j][i];
        }
    }   

    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            cout << array_t[j][i] << ' '; 
        }
        cout << '\n'; */

    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            cout << array[i][j] << ' '; 
        }
        cout << '\n';
    }  
    return 0;
}

