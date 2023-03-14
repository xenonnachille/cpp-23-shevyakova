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
    std::ofstream out("strategyC_.csv", std::ios::out);
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

void fill_zeros(int* ptr, int n) {
    for (int i = 0; i < n; i++) {
        *(ptr + i) = 0;
    }
}

void strategy_C(int* ptr, int* help_ptr, int n, int key){
    int i = search(ptr, n, key);
    *(help_ptr + i + 1) += 1; // help_arr = {k(-1), k(0), ..., k(n-1)}
    if (i > 0) {
        if (*(help_ptr + i + 1) > *(help_ptr + i)) {
            swap(*(ptr + i), *(ptr + i-1));
            swap(*(help_ptr + i + 1), *(help_ptr + i));
        }
    }
}



int main() {
    int key = 0;
    
    double* ans = nullptr;  // массив усредненных времен для каждого эксперимента 
    ans = new double[2000];
    for (int N = 100; N < 100000; N += 100) {
        int time_C_neravn = 0, time_C_ravn = 0;
        int i = 1;
        unsigned seed2 = N*7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, N+1);  
        int* data = nullptr;  // массив данных
        int* help_data = nullptr;
        data = new int[N];
        help_data = new int[N+1];
        //равномерно:
        for (int repeats = 0; repeats < 100; ++repeats) { 
            randomize(data, N, N*500/i);
            fill_zeros(help_data, N);
            auto begin = std::chrono::steady_clock::now();
            // если хотим измерить влияние выделения памяти на скорость, переносим сюда выделение памяти и рандомизацию
            key = dstr2(rng);
            strategy_C(data, help_data, N, key);
            i++;
            auto end = std::chrono::steady_clock::now();
            auto time_span_C_r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
            time_C_ravn += time_span_C_r.count();

           *(ans + 2*(N/100 - 1)) = time_C_ravn/100.0;
        }

        //неравномерно: ищутся элементы только из первой четверти массива
        i = 1;
        auto begin = std::chrono::steady_clock::now();
        for (int repeats = 0; repeats < 100; ++repeats) { 
            randomize(data, N, N*500/i);
            fill_zeros(help_data, N);
            i++;
            key = dstr2(rng);
            int key_n = *(data + 0);
            for (int i = N/4; i < N; ++i) {
                if (key == *(data + i)) {
                    key = key_n;
                }
            }
            strategy_C(data, help_data, N, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        time_C_neravn += time_span.count();
        delete [] data;
        delete [] help_data;

        *(ans + 2*(N/100 - 1) + 1) = time_C_neravn/100.0;
        
    }
    create_outfile(ans, 999, 100);
    delete [] ans;
    return 0;
}