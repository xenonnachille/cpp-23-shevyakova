#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 7
#endif

int main() {
    int array[N];
    for (int i = 0; i < N; ++i) {
        cin >> array[i]; 
    }
    std::sort(array, array + N);
    for (int i = 0; i < N; ++i) {
        cout << array[i] << ' '; 
    }
    cout << '\n';
    int lonely_num = array[0];
    for (int i = 1; i < N; ++i) {
        if (array[i] != lonely_num and array[i] == array[i-1]) {
            lonely_num = array[i];
        } else if (array[i] == lonely_num and array[i] == array[i-1]) {
            lonely_num = array[i+1];
        }
    }
    cout << lonely_num << '\n';
    return 0;
}