#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void input_array(int* ptr, int N) {
    for (int i = 0; i < N; i++) {
        cin >> ptr[i];
    }
}


void reverse(int* ptr, int N) {
    for(int i = 0; i < N/2; i++) {
        int tmp = *(ptr + i);
        *(ptr + i) = *(ptr + N - i - 1);
        *(ptr + N - i - 1) = tmp;
    }
}

void print(const int* ptr, int N) {
    for (int i = 0; i < N; i++) {
        cout << ptr[i] << ' ';
    }
    cout << endl;
}




int main() {
    int N = 0;
    int* ptr = nullptr;
    cin >> N;
    ptr = new int[N];

    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    delete [] ptr; 
    return 0;
}