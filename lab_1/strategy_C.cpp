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


void strategy_C(int array[], int help_arr[], int n, int key){
    int i = search(array, n, key);
    help_arr[i+1]++; // help_arr = {k(-1), k(0), ..., k(n-1)}
    if (i > 0) {
        if (help_arr[i+1] > help_arr[i]) {
            swap(array[i], array[i-1]);
        }
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
    out.open("strategy_C.csv");
    out << "N,time_ravnomerno,time_ne_ravnomerno" << std::endl;
    
    for(unsigned counter = 100; counter < N; counter += 10000) {
        int array[counter];
        int helping_array[counter+1] = {0};
        randomize(array, counter);
        unsigned seed2 = counter*7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, counter+1);  
        //равномерно:
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            key = dstr2(rng);
            strategy_C(array, helping_array, counter, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span_C_r = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 
        
        //неравномерно: ищутся элементы только из первой четверти массива
        randomize(array, counter);
        auto begin_n = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            key = dstr2(rng);
            int key_n = array[0];
            for (int i = counter/4; i < counter; ++i) {
                if (key == array[i]) {
                    key = key_n;
                }
            }
            strategy_C(array, helping_array, counter, key);

        }
        auto end_n = std::chrono::steady_clock::now();
        auto time_span_C_n = std::chrono::duration_cast<std::chrono::microseconds>(end_n - begin_n); 

        if (out.is_open()) {
            out << counter << ',' << (float) time_span_C_r.count()/10000 << ',' << (float) time_span_C_n.count()/10000 << std::endl;
        }
    }
    out.close();
    return 0;
}