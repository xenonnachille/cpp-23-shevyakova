#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int &i, int &j) {
    int tmp = j;
    j = i;
    i = tmp;
    return;
}

void gnome_sort(int array[], int N) {
    int i = 1;
    int j = 2;
    while (i < N) {
        if (array[i - 1] < array[i]) {
            i = j;
            j++;
        } else {
            swap (array[i - 1], array[i]);
            i--;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
}

int main() {
    int S = 0, N, i = 0;
    cin >> S >> N;
    int mem[N];
    for (i = 0; i < N; i++) {
        cin >> mem[i];
    }
    gnome_sort(mem, N);
    int s = 0, cnt = 0;;
    i = 0;
    while (s < S) {
        if (s + mem[i] <= S) {
            s += mem[i];
            i++;
            cnt++;
        } else {
            break;
        }
    }

    cout << cnt << endl;   
    return 0;
}