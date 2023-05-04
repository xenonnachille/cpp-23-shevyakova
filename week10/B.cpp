#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int main() { 
    int length[5] = {10, 6, 3, 2, 1}; 
    int price[5] = {30, 17, 8, 5, 1}; 
 
    int n = 0; 
    cin >> n; 
 
    int iterator = 0; 
    while (n - length[iterator] < 0) { 
        ++iterator; 
    } 
 
    int za_dengi_da = 0; 
    while (n != 0) { 
        while (n - length[iterator] >= 0) { 
            if (n == 4) { 
                iterator = 3; 
            } 

            n -= length[iterator]; 
            za_dengi_da += price[iterator]; 
        } 
        ++iterator; 
    } 

    cout << za_dengi_da; 
    return 0; 
}