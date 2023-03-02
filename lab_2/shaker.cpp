#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

#ifndef N
#define N 17
#endif

unsigned array[N];

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

void backward_step(unsigned array[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = begin_idx; i > end_idx; i--) {
        if (array[i - 1] > array[i]) {
            swap(array[i], array[i - 1]);
        }
    }
    return;
}


void shaker_sort(unsigned array[], unsigned const begin_idx, unsigned const end_idx) {
    unsigned left = begin_idx, right = end_idx;
    while (left <= right) {
        forward_step(array, left, right);
        right--;
        backward_step(array, right, left);
        left++;
    }
}




int main() {
    unsigned seed = 1000-7;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N-1);

    for (int i = 0; i < N; i++) {
        array[i] = dstr(rng);
        cout << array[i] << ' ';
    }
    cout << endl;

    shaker_sort(array, 0, N-1);

    for (int i = 0; i < N-1; i++) {
        cout << array[i] << ' ';
    }
    cout << array[N-1] << endl;
    return 0;
}


