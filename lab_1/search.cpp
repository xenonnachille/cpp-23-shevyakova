#include <iostream>
#include <fstream>
#include <chrono>
#include <random>


using std::cout;
using std::endl;
using std::cin;

#ifndef N
#define N 500000
#endif

unsigned seed = 5;
std::default_random_engine rng(seed);
std::uniform_int_distribution<unsigned> dstr(0, N-1);
int arr[N];
int array[N];
int sorted_array[N];



void search(int array[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (array[i] == key) {
            return;
        }
    }
    return;
}

void binsearch(int array[], int n, int key) {
    int iterator = 0, left = 0, right = n-1;
    if (array[0] == key) {
        return;
    } else if (array[n-1] == key) {
        return;
    }
    while (left < right - 1) {
        iterator = (left + right)/2;
        if (array[iterator] == key) {
            return;
        } else if (array[iterator] < key) {
            left = iterator;
        } else {
            right = iterator;
        }
    }
    return;
}


void randomize(int array[], int n){
    for (int i = 0; i < n; i++)
    {
        array[i] = arr[dstr(rng)];
    }
}


int main() {
    int key = 0;
    for (int i = 0; i < N; i++) {
        sorted_array[i] = i;
        array[i] = i;
    }

    std::ofstream out;
    out.open("search_times.csv");
    out << "N,time_search,time_binsearch" << std::endl;
    
    for(unsigned counter = 100; counter < N; counter += 10000) {
        key = array[dstr(rng)];
        
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            search(array, counter, -1);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 

        auto begin2 = std::chrono::steady_clock::now();
        for (unsigned cnt = 100000; cnt != 0 ; --cnt) {
            binsearch(sorted_array, counter, -1);
        }
        auto end2 = std::chrono::steady_clock::now();
        auto time_span2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2); 
        if (out.is_open()) {
            out << counter << ',' << (float) time_span.count()/10000 << "," << (float) time_span2.count()/100 << std::endl;
        }
    }
    out.close();
    return 0;
}