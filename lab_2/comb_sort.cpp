#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

#ifndef N
#define N 100000
#endif

unsigned array[N];
unsigned counter_of_swaps = 0;


void swap(unsigned &lha, unsigned &rha) {
    unsigned tmp = rha;
    rha = lha;
    lha = tmp;
    return;
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
    bool marker = false;
    while (!marker) {
        unsigned cnt = counter_of_swaps;
        check_order(array, n, 1);
        marker = (cnt == counter_of_swaps);
    }

    return;
}



int main() {
    std::ofstream out;
    out.open("combsort.csv");
    out << "N,time,number of swaps" << std::endl;

    for(unsigned counter = 100; counter < N; counter += 5000) {
        unsigned array[counter];
        randomize(array, counter);
        counter_of_swaps = 0;
        auto begin = std::chrono::steady_clock::now();
        CombSort(array, counter);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin); 
        if (out.is_open()) {
            out << counter << ',' << (float) time_span.count() << "," << counter_of_swaps << std::endl;
        }
    }
    out.close();

    return 0;
}