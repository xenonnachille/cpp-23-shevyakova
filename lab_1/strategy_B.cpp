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

void strategy_B(int array[], int n, int key){
    int i = search(array, n, key);
    if (i != -1 and i != 0) {
        swap(array[i], array[i-1]);
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
    out.open("strategy_B.csv");
    out << "N,time_ravnomerno,time_ne_ravnomerno" << std::endl;
    
    for(unsigned counter = 100; counter < N; counter += 10000) {
        unsigned seed2 = counter*7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, N-1);  
        randomize(array, counter);
        key = dstr2(rng);

        //равномерно:
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            strategy_B(array, counter, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span_A_r = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 
        
        //неравномерно: ищутся элементы только из первой четверти массива
        randomize(array, counter);
        int key_n = array[0];
        for (int i = counter/4; i < counter; ++i) {
            if (key == array[i]) {
                key = key_n;
            }
        }

        auto begin_n = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            strategy_B(array, counter, key);
        }
        auto end_n = std::chrono::steady_clock::now();
        auto time_span_A_n = std::chrono::duration_cast<std::chrono::microseconds>(end_n - begin_n); 

        if (out.is_open()) {
            out << counter << ',' << (float) time_span_A_r.count()/10000 << ',' << (float) time_span_A_n.count()/10000 << std::endl;
        }
    }
    out.close();
    return 0;
}