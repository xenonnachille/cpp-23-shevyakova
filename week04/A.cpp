// gnome sort
#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl; 

#ifndef N
#define N 10
#endif

void swap(int &i, int &j) {
    int tmp = j;
    j = i;
    i = tmp;
    return;
}

void gnome_sort(int (&array)[N]) {
    int i = 1;
    int j = 2;
    while (i < N) {
        if (array[i - 1] < array[i]) {
            i = j;
            j++;
        } else {
            swap (array[i - 1], array[i]);
            i--;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
}

int main() {
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    gnome_sort(array);
    for (int i = 0; i < N-1; i++) {
        cout << array[i] << ' ';
    }
    cout << array[N-1] << endl;
    return 0;
}