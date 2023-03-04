#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

#ifndef N
#define N 500101
#endif

unsigned array[N];
unsigned counter_of_swaps = 0;


// unsigned seed = 666;
// std::default_random_engine rng(seed);


void swap(unsigned &lha, unsigned &rha) {
    unsigned tmp = rha;
    rha = lha;
    lha = tmp;
    return;
}
/* void randomize(unsigned array[], unsigned n){
    std::uniform_int_distribution<unsigned> dstr(0, n-1);
    for (int i = 0; i < n; i++)
    {
        array[i] = dstr(rng);
    }
} */

void check_order(unsigned array[], unsigned n, unsigned step) {
    for (int i = 0; i < n - step; i++) {
        if (array[i] > array[i + step]) {
            swap(array[i], array[i + step]);
            counter_of_swaps++;
        }
    }
    return;
}

void CombSort(unsigned array[], unsigned n) {
    unsigned step = n/2;
    while (step > 0) {
        check_order(array, n, step);
        step /= 2;
    }
    bool marker = true;
    unsigned h_arr[n];
    while (marker) {
        for (int i = 0; i < n; i++) {
            h_arr[i] = array[i];
        }
        check_order(array, n, 1);
        int ind = -1; 
        for (int i = 0; i < n; i++) {
            if (h_arr[i] != array[i]) {
                ind = i;
            }
        }
        if (ind == -1) {
            marker = false;
        }
    }

    return;
}

void antisorted(unsigned array[], unsigned n) {
    for (int i = 0; i < n; i++) {
        array[i] = n - 1 - i;
    }
}

int main() {
    std::ofstream out;
    out.open("combsort.csv");
    out << "N,time,number of swaps" << std::endl;

    
    /* unsigned seed = 1000-7;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N-1); */
    

    for(unsigned counter = 100; counter < N; counter += 1000) {
        antisorted(array, counter);
        counter_of_swaps = 0;
        auto begin = std::chrono::steady_clock::now();
        CombSort(array, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 
        if (out.is_open()) {
            out << counter << ',' << (float) time_span.count() << "," << counter_of_swaps << std::endl;
        }
    }
    out.close();

    return 0;
}