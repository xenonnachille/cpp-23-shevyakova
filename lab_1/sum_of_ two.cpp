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

void sum_of_two(int array[], int n, int sum) {
    for (int i = 0; i < n; i++) {
        int key = sum - array[i];
        for (int j = i + 1; j < n; j++) {
            if (array[j] == key) {
            // cout << i << " and " << j << ": " << array[i] <<
            // " + " << array[j] << " = " << sum << '\n';
            return;
            }
        }
    }
    // cout << "no such numbers in this array ;(" << '\n';
    return;
}

void sum_of_two_for_sorted(int array[], int n, int sum) {
    int i = 0, j = n-1;
    while ((i < n - 1) and (j > 0)) {
        if (array[i] + array[j] == sum) {
            // cout << i << ' ' << j << endl; 
            return;
        } else if (array[i] + array[j] > sum) {
            j--;
        } else {
            i++;
        }
    }      
    // cout << "no such numbers in this array ;(" << '\n';
    return;
}

int main() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sorted_array[i] = i;
        array[i] = i;
    }
    
    std::ofstream out;
    out.open("sum.csv");
    out << "N,time_simple,time_sorted" << std::endl;
    
    for(unsigned counter = 100; counter < N; counter += 5000 ) {
        
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10; cnt != 0 ; --cnt) {
            sum_of_two(sorted_array, counter, 0);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin); 

        auto begin2 = std::chrono::steady_clock::now();
        for (unsigned cnt = 10; cnt != 0 ; --cnt) {
            sum_of_two_for_sorted(sorted_array, counter, 0);
        }
        auto end2 = std::chrono::steady_clock::now();
        auto time_span2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2); 
        if (out.is_open()) {
            out << counter << ',' << (float) time_span.count()/10 << "," << (float) time_span2.count()/10 << std::endl;
        }
    }
    out.close();
    return 0;
}