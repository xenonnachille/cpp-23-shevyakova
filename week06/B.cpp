#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Students
{
    string name;
    int srebal;
};

void swap(int &lha, int &rha) {
    int tmp = lha;
    lha     = rha;
    rha     = tmp;
}

void swap_string(string &lha, string &rha) {
    string tmp = lha;
    lha        = rha;
    rha        = tmp;
}

int main() {
    int M = 0, N = 0;
    cin >> N;
    Students data[N];
    int points[N];

    for (int i = 0; i < N; i++) {
        cin >> (data[i]).name >> (data[i]).srebal;
    }
    cin >> M;

    string ans[N];

    int n = 0;
    for (int i = 0; i < N; i++) {
        if ((data[i]).srebal > M) {
            ans[n]    = (data[i]).name;
            points[n] = (data[i]).srebal;
            n++;
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (points[j] >= points[j + 1]) {
                if (points[j] == points[j + 1]) {
                    if ((ans[j]).compare(ans[j + 1]) > 0) {
                        swap_string(ans[j], ans[j + 1]);
                    }
                } else {
                    swap(points[j], points[j + 1]);
                    swap_string(ans[j], ans[j + 1]);
                }
            }
        }
    }

    for (int k = 0; k < n - 1; k++) {
        cout << ans[k] << ' ';
    }
    cout << ans[n - 1] << endl;
    return 0;
}