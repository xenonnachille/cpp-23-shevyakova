#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 5
#endif


int binsearch(int (&array)[N]) {
    int iterator = 0, left = 0, right = N-1;
    while (left < right) {
        iterator = (left + right)/2;
        if (array[iterator] == 1) {
            right = iterator;
        } else {
            left = iterator;
        }
        if (left == right - 1) {
            return left;
        }
    }
    return left - 1;
}

int main() {
    int array[N];
    for (int i = 0; i < N; ++i) {
        cin >> array[i]; 
    }   
    cout << binsearch(array) << endl;
    return 0;
}
