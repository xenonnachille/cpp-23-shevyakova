#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using std::cout;
using std::endl;
using std::cin;

void randomize(int* ptr, size_t N, int seed){
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    for (int i = 0; i < N; i++)
    {
        *(ptr + i) = dstr(rng);
    }
}

void create_outfile(double* ptr, size_t N, int step) {
    std::ofstream out("strategyA_.csv", std::ios::out);
    out << "N,time_r,time_n" << endl;
    for (int i = 0; i < N/2; ++i) {
        if (out.is_open()) {
            out << step * (i + 1) << "," << ptr[2*i] << ',' << ptr[2*i+1] << endl;
        }
    }
    out.close();
}


int search(int* ptr_array, int N, int key) {
    for (int i = 0; i < N; i++) {
        if (*(ptr_array + i) == key) {
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

void strategy_A(int* ptr_arr, int n, int key){
    int i = search(ptr_arr, n, key);
    if (i != -1 and i != 0) {
        swap(*(ptr_arr + i), *(ptr_arr + 0));
    }
}



int main() {
    int key = 0;
    
    double* ans = nullptr;  // массив усредненных времен для каждого эксперимента 
    ans = new double[2000];
    for (int N = 100; N < 100000; N += 100) {
        int time_A_neravn = 0, time_A_ravn = 0;
        int i = 1;
        unsigned seed2 = N*7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, N+1);  
        int* data = nullptr;  // массив данных
        data = new int[N];
        //равномерно:
        for (int repeats = 0; repeats < 100; ++repeats) { 
            randomize(data, N, N*500/i);
            auto begin = std::chrono::steady_clock::now();
            // если хотим измерить влияние выделения памяти на скорость, переносим сюда выделение памяти и рандомизацию
            key = dstr2(rng);
            strategy_A(data, N, key);
            i++;
            auto end = std::chrono::steady_clock::now();
            auto time_span_A_r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
            time_A_ravn += time_span_A_r.count();

           *(ans + 2*(N/100 - 1)) = time_A_ravn/100.0;
        }
        

        //неравномерно: ищутся элементы только из первой четверти массива
        i = 1;
        auto begin = std::chrono::steady_clock::now();
        for (int repeats = 0; repeats < 100; ++repeats) { 
            // если хотим измерить влияние выделения памяти на скорость, переносим сюда выделение памяти
            randomize(data, N, N*500/i);
            i++;
            key = dstr2(rng);
            int key_n = *(data + 0);
            for (int i = N/4; i < N; ++i) {
                if (key == *(data + i)) {
                    key = key_n;
                }
            }
            strategy_A(data, N, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        time_A_neravn += time_span.count();
        delete [] data;

        *(ans + 2*(N/100 - 1) + 1) = time_A_neravn/100.0;
        
    }
    create_outfile(ans, 999, 100);
    delete [] ans;
    return 0;
}