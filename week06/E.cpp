#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

enum Status
{
    BAD  = -1,
    GOOD = 1,
    CE   = 0
};

struct segment
{
    int beginning;
    int ending;
};

void swap(int &lha, int &rha) {
    int tmp = lha;
    lha     = rha;
    rha     = tmp;
}

int main() {
    int success = 0, N = 0;
    segment data[N];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> (data[i]).beginning >> (data[i]).ending;
        if (data[i].beginning > data[i].ending) {
            swap(data[i].beginning, data[i].ending);
        }
    }

    if (N == 1) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (data[i].beginning > data[i + 1].ending or data[i + 1].beginning > data[i].ending) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}