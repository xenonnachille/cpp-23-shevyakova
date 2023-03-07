#include <iostream>
#include <random>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

#ifndef N
#define N 100000
#endif

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

void randomize(unsigned array[], unsigned n){
    unsigned seed = 10000;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, n-1);
    for (int i = 0; i < n; i++)
    {
        array[i] = dstr(rng);
    }
} 


int main() {
    int cnt = N;
    while (cnt > 1) {
        unsigned array[cnt];
        unsigned correct_array[cnt];
        randomize(array, cnt);
        randomize(correct_array, cnt);

        shaker_sort(array, 0, cnt-1);
        std::sort(correct_array, correct_array + cnt);
        if (! std::equal(array, array + cnt, correct_array)) {
            cout << "something wrong!";
            return 0;
        }
        cnt -= 10000;
    }
    cout << "good job!";
    return 0;
}


