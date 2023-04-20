#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int array[6] = {1, 7, 28, 49, 63, 98};
    int M = 0, i = 1, k = 0, s = 0;
    cin >> M;
    while (s + array[5] <= M){
        k++;
        s += array[5];
    }
    i = 1;
    while (s + array[4] <= M){
        k++;
        s += array[4];
        i++;
    }
    i = 1;
    while (s + array[3] <= M){
        k++;
        s += array[3];
        i++;
    }    
    i = 1;
    while (s + array[2] <= M){
        k++;
        s += array[2];
        i++;
    }    
    i = 1;
    while (s + array[1] <= M){
        k++;
        s += array[1];
        i++;
    }
    i = 1;
    while (s + array[0] <= M){
        k++;
        s += array[0];
        i++;
    }
    cout << k << endl;
    return 0;
}
