#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

using std::cin;
using std::cout;
using std::endl;

void randomize(int* ptr, size_t N, int seed){
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    for (int i = 0; i < N; i++)
    {
        *(ptr + i) = dstr(rng);
    }
}

void create_outfile(double* ptr, size_t N, int step) {
    std::ofstream out("linsearch_extratime.csv", std::ios::out);
    for (int i = 0; i < N; ++i) {
        if (out.is_open()) {
            out << step * (i + 1) << "," << ptr[i] << endl;
        }
    }
    out.close();
}


void search(int* ptr_array, int N, int key) {
    for (int i = 0; i < N; i++) {
        if (*(ptr_array + i) == key) {
            return;
        }
    }
    return;
}

int main() {
    double* ans = nullptr;  // массив усредненных времен для каждого эксперимента 
    ans = new double[2000];

    for (int N = 100; N < 100000; N += 100) {
        int i = 1; // это чтобы ну совсем рандомный массив генерить, не знаю, зачем
        int time_all = 0; // чтобы время для каждого эксперимента отдельно считалось
        //int* data = nullptr; // массив данных переехал сюда, не бейте
        //data = new int[N]; переместились отсюда в блок с измерением времени для оценки влияния выделения памяти на скорость
        for (int repeats = 0; repeats < 100; ++repeats) { 
            auto begin = std::chrono::steady_clock::now();
            int* data = nullptr; // массив данных переехал сюда, не бейте
            data = new int[N];
            randomize(data, N, N*500/i);
            search(data, N, -1);
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            time_all += time_span.count();
            i++;
            delete [] data;
        }
        *(ans + N/100 - 1) = time_all/100.0;
    }
    create_outfile(ans, 999, 100);
    delete [] ans;
    return 0;
}