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

void family_triangle(int (&array)[N], int parent_ind, int size){
    if (2 * parent_ind + 1 <= size and array[parent_ind] < array[2 * parent_ind + 1]) {
        swap(array[parent_ind], array[2 * parent_ind + 1]);
    }

    if(2 * parent_ind + 2 <= size and array[parent_ind] < array[2 * parent_ind + 2]) {
        swap(array[parent_ind], array[2 * parent_ind + 2]);
    }
}

void cheops_sort(int (&array)[N], int i, int size) { // i - cколько осталось несортированных элементов (?)
    if (i == 0) {
        return;
    }

    for (int cnt = i; cnt >= 0; cnt--) {
        family_triangle(array, cnt, i); // начинаем сортировать снизу
    }
    swap(array[0], array[i]); // меняем самого старшего родителя с последним несортированным элементом
    cheops_sort(array, i-1, size);
}
    

int main() {
    int array[N];
        
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    cheops_sort(array, N-1, N);

    for (int i = 0; i < N-1; i++) {
        cout << array[i] << ' ';
    }
    cout << array[N-1] << endl;
    
    return 0;
}