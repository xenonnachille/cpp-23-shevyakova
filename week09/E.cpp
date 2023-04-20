#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int N = 0, k = 0, S = 0, cnt = 0;
    cin >> N >> k >> S;
    int arr[S];
    for (int i = 0; i < S; i++) {
        cin >> arr[i];
    }

    if (k > N) {
        cout << 0 << endl;
        return 0;
    }

    if (arr[0] > k) {
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 0; i < S - 1; i++) {
        if (arr[i + 1] - arr[i] > k) {
            cout << -1 << endl;
            return 0;
        }
    }

    cnt = 0;
    int l = 0; //сколько уже проехал
    for (int i = 0; i < S - 1; i++) {
        if (arr[i + 1] - l > k) {
            l = arr[i];
            cnt++;
        }
    }
    cout << ++cnt << endl;
    return 0;
}