#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool reserve_memory(size_t N, int *ptr) {
    if (ptr != nullptr) {
        return false;
    }
    ptr = new int[N];
    return true;
}
void free_memory(int* ptr) {
    delete [] ptr;
}



int main() {
    int N = 0;
    int* ptr = nullptr;
    cin >> N;
    cout << reserve_memory(N, ptr) << endl;
    free_memory(ptr);
    return 0;
}