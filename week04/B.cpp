// qsort sort
#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl; 

#ifndef N
#define N 9
#endif

void swap(int& lha, int& rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}


void qsort(int (&array)[N], int ind_left_base, int ind_right_base) {
    if (ind_left_base < ind_right_base) {
        int pivo = (ind_left_base + ind_right_base) / 2;
        int ind_left = ind_left_base, ind_right = ind_right_base;

        
        while (ind_left <= ind_right) {

            while (array[ind_left] < array[pivo]) {
                ind_left++;
            }

            while (array[ind_right] > array[pivo]) {
                ind_right--;
            }
            if (ind_left >= ind_right) {
                break;
            }
            swap(array[ind_left++], array[ind_right--]);
        }
        int p = ind_right;

        qsort(array, ind_left_base, p);
        qsort(array, p + 1, ind_right_base);
    }
}

int main() {
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    qsort(array, 0, N-1);
    for (int i = 0; i < N-1; i++) {
        cout << array[i] << ' ';
    }
    cout << array[N-1] << endl;
    return 0;
}