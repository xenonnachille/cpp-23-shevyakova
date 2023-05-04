#include <iostream> 
 
using std::cin;
using std::endl;
using std::cout;

int main() { 
    int length[]  = {10, 6, 3, 2, 1}; 
    int N = 0; 
    cin >> N; 
 
    int *ans = new int[N]; 
    int cnt = 0, iterator = 0; 

    while (N - length[iterator] < 0) { 
        ++iterator; 
    } 
 
    while (N != 0) { 
        while (N - length[iterator] >= 0) { 
            if (N == 4) { 
                iterator = 3; 
            } 

            N -= length[iterator]; 
            ans[cnt] = length[iterator]; 
            ++cnt; 
        } 
        ++iterator; 
    } 

    for (int i = cnt - 1; i > 0; --i) { 
        cout << ans[i] << ' '; 
    } 

    cout << ans[0] << endl;

    delete[] ans; 
    return 0; 
}