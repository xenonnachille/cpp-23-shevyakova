#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char *resize(const char *buf, size_t size, size_t new_size) {
    char* ptr = nullptr;
    ptr = new char[new_size];
    if (size < new_size) {
        for (int i = 0; i < size; i++) {
            *(ptr + i) = *(buf + i);
        }
    } else {
        for (int i = 0; i < new_size; i++) {
            *(ptr + i) = *(buf + i);
        }
    }
    return ptr;
}

int main() {
    int *a = new int[10];
    const char* ptr_0;
    resize(ptr_0, 10, 6);
    delete [] a;
}