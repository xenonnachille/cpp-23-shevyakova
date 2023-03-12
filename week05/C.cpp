#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int* ptr = nullptr;
    ptr = new int[1000000000];
    int a = -1, i = 0;
    while (a != 0) {
        cin >> a;
        *(ptr + i) = a;
        i++;
    }

    int* array = new int[i];
    for (int k = 0; k < i - 1; k++) {
        *(array + k) = *(ptr + k);
    }

    delete [] ptr;
    for (int k = 0; k < i - 2; k++) {
        cout << array[k] - array[k + 1] << ' ';
    }
    return 0;
}