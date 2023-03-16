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

int main() {
    int M = 0;
    Students data[10];
    for (int i = 0; i < 10; i++) {
        cin >> (data[i]).name >> (data[i]).srebal;
    }
    cin >> M;
    string ans[10];
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if ((data[i]).srebal > M) {
            ans[j] = (data[i]).name;
            j++;
        }
    }
    j--;
    for (int k = 0; k < j; k++) {
        cout << ans[k] << ' ';
    }
    cout << ans[j] << endl;
    return 0;
}