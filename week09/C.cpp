#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int k, M, s = 0, i = 1, cnt = 0;
    cin >> k;
    int array[k];
    for (int i = 0; i < k; ++i) {
        cin >> array[i];
    }
    cin >> M;
    k--;

    while (s < M) {
        i = 1;
        while (s + i * array[k] <= M) {
            ++i;
        }
        --i;
        s += i * array[k];
        cnt += i;
        --k;
    }
    cout << cnt << endl;
    return 0;
}