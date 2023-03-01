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

unsigned seed = 1000-7;
std::default_random_engine rng(seed);
std::uniform_int_distribution<unsigned> dstr(0, N-1);
int arr[N];
int array[N];



int search(int array[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

void swap(int &i, int &j) {
    int tmp = j;
    j = i;
    i = tmp;
    return;
}

void strategy_A(int array[], int n, int key){
    int i = search(array, n, key);
    if (i != -1 and i != 0) {
        swap(array[i], array[0]);
    }

}

void randomize(int array[], int n){
    std::uniform_int_distribution<unsigned> dstr(0, n-1);
    for (int i = 0; i < n; i++)
    {
        array[i] = dstr(rng);
    }
}


int main() {
    int key = 0;
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }




    std::ofstream out;
    out.open("strategy_A_r.csv");
    out << "N,time_search,time_binsearch" << std::endl;
    
    for(unsigned counter = 100; counter < N; counter += 10000) {
        randomize(array, counter);
        key = dstr(rng);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            search(array, counter, -1);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 

        if (out.is_open()) {
            out << counter << ',' << (float) time_span.count()/10000 << std::endl;
        }
    }
    out.close();
    return 0;
}