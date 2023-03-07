#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

void swap(unsigned &i, unsigned &j) {
    unsigned tmp = j;
    j = i;
    i = tmp;
    return;
}

void forward_step(unsigned array[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = begin_idx; i < end_idx; i++) {
        if (array[i] > array[i + 1]) {
            swap(array[i], array[i + 1]);
        }
    }
    return;
}


int main() {
    // я думала что-то с количеством инверсий намутить, но это сложнее всей функции, так что тут вручную)) 
    // вообще сам факт, что сортировка работает, как будто говорит о том, что функции работают, но ладно...
    
    unsigned array1[10] = {0, 3, 0, 5, 6, 5, 4, 6, 9, 9};

    unsigned array2[50] = {3, 18, 2, 25, 33, 29, 22, 32, 48, 46, 1, 8, 32, 36, 30, 0, 24, 49, 7, 21, 42, 36, 38, 18, 33, 14, 32, 9, 49, 45, 10, 
                            49, 26, 32, 40, 17, 19, 5, 18, 19, 19, 25, 30, 27, 9, 42, 17, 3, 4, 5};

    unsigned array3[5] = {0, 1, 0, 2, 3};

    unsigned array4[25] = {1, 9, 1, 12, 16, 14, 11, 16, 24, 23, 0, 4, 16, 18, 15, 0, 12, 24, 3, 10, 21, 18, 19, 9, 16};

    unsigned array5[33] = {2, 12, 1, 16, 22, 19, 14, 21, 31, 30, 0, 5, 21, 23, 20, 0, 16, 32, 5, 13, 28, 23, 25, 
                            12, 22, 9, 21, 6, 32, 29, 6, 32, 17};

    unsigned array6[42] = {3, 15, 2, 21, 28, 24, 18, 27, 40, 39, 0, 6, 27, 30, 25, 0, 20, 41, 6, 17, 36, 30, 32, 15, 28, 12, 
                            27, 7, 41, 38, 8, 41, 22, 27, 34, 14, 16, 4, 15, 16, 16, 21};

    unsigned array7[17] = {1, 6, 0, 8, 11, 10, 7, 11, 16, 15, 0, 2, 11, 12, 10, 0, 8};

    unsigned array8[8] = {0, 3, 0, 4, 5, 4, 3, 5};

    
    unsigned ans_array1[10] = {0, 0, 3, 5, 5, 4, 6, 6, 9, 9};

    unsigned ans_array2[50] = {3, 2, 18, 25, 29, 22, 32, 33, 46, 1, 8, 32, 36, 30, 0, 24, 48, 7, 21, 42, 36, 38, 18, 33, 14, 32, 9, 49, 
                                45, 10, 49, 26, 32, 40, 17, 19, 5, 18, 19, 19, 25, 30, 27, 9, 42, 17, 3, 4, 5, 49};

    unsigned ans_array3[5] = {0, 0, 1, 2, 3};

    unsigned ans_array4[25] = {1, 1, 9, 12, 14, 11, 16, 16, 23, 0, 4, 16, 18, 15, 0, 12, 24, 3, 10, 21, 18, 19, 9, 16, 24};

    unsigned ans_array5[33] = {2, 1, 12, 16, 19, 14, 21, 22, 30, 0, 5, 21, 23, 20, 0, 16, 31, 5, 13, 28, 
                                23, 25, 12, 22, 9, 21, 6, 32, 29, 6, 32, 17, 32};

    unsigned ans_array6[42] = {3, 2, 15, 21, 24, 18, 27, 28, 39, 0, 6, 27, 30, 25, 0, 20, 40, 6, 17, 36, 30, 32, 15, 28, 12, 
                                27, 7, 41, 38, 8, 41, 22, 27, 34, 14, 16, 4, 15, 16, 16, 21, 41};

    unsigned ans_array7[17] = {1, 0, 6, 8, 10, 7, 11, 11, 15, 0, 2, 11, 12, 10, 0, 8, 16};

    unsigned ans_array8[8] = {0, 0, 3, 4, 4, 3, 5, 5};

    forward_step(array1, 0, 9);
    forward_step(array2, 0, 49);
    forward_step(array3, 0, 4);
    forward_step(array4, 0, 24);
    forward_step(array5, 0, 32);
    forward_step(array6, 0, 41);
    forward_step(array7, 0, 16);
    forward_step(array8, 0, 7);

    int marker = 0;
    if (std::equal(array1, array1 + 10, ans_array1)) {
        marker++;
    } else {
        marker = 0;
    }

    if (std::equal(array2, array2 + 50, ans_array2)) {
        marker++;
    } else {
        marker = 0;
    }

    if (std::equal(array3, array3 + 5, ans_array3)) {
        marker++;
    } else {
        marker = 0;
    }

    if (std::equal(array4, array4 + 25, ans_array4)) {
        marker++;
    } else {
        marker = 0;
    }

    if (std::equal(array5, array5 + 33, ans_array5)) {
        marker++;
    } else {
        marker = 0;
    }

    if (std::equal(array6, array6 + 42, ans_array6)) {
        marker++;
    } else {
        marker = 0;
    }

    if (std::equal(array7, array7 + 17, ans_array7)) {
        marker++;
    } else {
        marker = 0;
    }

    if (std::equal(array8, array8 + 8, ans_array8)) {
        marker++;
    } else {
        marker = 0;
    }
    
    if (marker == 8) {
        cout << "function works correctly";
    } else {
        cout << "something wrong " << marker;
    }


    return 0;
}