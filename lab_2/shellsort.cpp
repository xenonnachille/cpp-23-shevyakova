#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

#ifndef N
#define N 200000
#endif

unsigned array[N];
unsigned counter_of_swaps = 0; // not really swaps но я не придумала более мудрое название

void shellsort(unsigned array[], unsigned n) {
    for (unsigned step = n/2; step > 0; step /= 2) {
        for (unsigned i = step; i < n; i++) {
            unsigned helping_num = array[i];
            unsigned j;
            for (j = i; j >= step and array[j - step] > helping_num; j -= step) {
                array[j] = array[j - step];
                counter_of_swaps++;
            }
            array[j] = helping_num;
            counter_of_swaps++;
        }
    }
    return;
}


unsigned intpower(unsigned base, unsigned power) {
    unsigned res = 1;
    for (unsigned i = 0; i < power; i++) {
        res *= base;
    }
    return res;
}

void hibshellsort(unsigned array[], unsigned n) {
    for (unsigned k = log2(n + 1); k > 0; k--) {
        unsigned step = intpower(2, k) - 1;
        for (unsigned i = step; i < n; i++) {
            unsigned helping_num = array[i];
            unsigned j;
            for (j = i; j >= step and array[j - step] > helping_num; j -= step) {
                array[j] = array[j - step];
                counter_of_swaps++;
            }
            array[j] = helping_num;
            counter_of_swaps++;
        }
    }

    return;
}

unsigned fibonacci(unsigned i) {
    if (i == 0) {
        return 1;
    }
    if (i == 1) {
        return 1;
    }
    return fibonacci(i - 1) + fibonacci(i - 2);
}

void fibshellsort(unsigned array[], unsigned n) {
    int k = 0;
    while (fibonacci(k) < n) {
        k++;
    }
    k--;
    for (k; k > 0; k--) {
        unsigned step = fibonacci(k);
        for (unsigned i = step; i < n; i++) {
            unsigned helping_num = array[i];
            unsigned j;
            for (j = i; j >= step and array[j - step] > helping_num; j -= step) {
                array[j] = array[j - step];
                counter_of_swaps++;
            }
            array[j] = helping_num;
            counter_of_swaps++;
        }
    }

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

int main() {
    std::ofstream out;
    out.open("shellsort.csv");
    out << "N,time_s,numberofswaps_s,time_h,numberofswaps_h,time_f,numberofswaps_f" << std::endl;

    for(unsigned counter = 100; counter < N; counter += 10000) {
        unsigned array[counter];
        randomize(array, counter);
        counter_of_swaps = 0;
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100; cnt != 0 ; --cnt) {
            randomize(array, counter);
            shellsort(array, counter);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span1 = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 
        unsigned counter_of_swaps1 = counter_of_swaps;

        randomize(array, counter);
        counter_of_swaps = 0;
        auto begin2 = std::chrono::steady_clock::now();
        for (unsigned cnt = 100; cnt != 0 ; --cnt) {
            randomize(array, counter);
            hibshellsort(array, counter);
        }
        auto end2 = std::chrono::steady_clock::now();
        auto time_span2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
        unsigned counter_of_swaps2 = counter_of_swaps;

        randomize(array, counter);
        counter_of_swaps = 0;
        auto begin3 = std::chrono::steady_clock::now();
        for (unsigned cnt = 100; cnt != 0 ; --cnt) {
            randomize(array, counter);
            fibshellsort(array, counter);
        }
        auto end3 = std::chrono::steady_clock::now();
        auto time_span3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - begin3);
        unsigned counter_of_swaps3 = counter_of_swaps;

        if (out.is_open()) {
            out << counter << ',' << time_span1.count()/100.0 << "," << counter_of_swaps1/10000 << ',' <<
                                    time_span2.count()/100.0 << "," << counter_of_swaps2/10000 << ',' <<
                                    time_span3.count()/100.0 << "," << counter_of_swaps3/10000 << std::endl;
        }
    }
    out.close();
    return 0;
}
