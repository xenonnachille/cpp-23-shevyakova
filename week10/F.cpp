#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int fixprice(int* sizes, int n) { 
    int** arr = new int*[n]; 
    for (int i = 0; i < n; i++) { 
        arr[i] = new int[n];
    }
    for (int i = 1; i < n; i++) { 
        arr[i][i] = 0;
    }

    for (int L = 2; L < n; L++) { 
        for (int i = 1; i < n - L + 1; i++) { 
            int j = i + L - 1;
            arr[i][j] = 1000000; 
            for (int k = i; k <= j - 1; k++) { //возможные разбиения цепочки матриц на две подцепочки
                int price = arr[i][k] + arr[k + 1][j] + sizes[i - 1] * sizes[k] * sizes[j]; //стоимость умножения текущих подцепочек матриц
                if (price < arr[i][j]) {
                    arr[i][j] = price; 
                }
            }
        }
    }

    int cost = arr[1][n - 1]; //минимальная стоимость умножения всей цепочки матриц

    for (int i = 0; i < n; i++) { 
        delete[] arr[i];
    }
    delete[] arr;
    return cost; 
}

int main() { 
    int n;
    cin >> n; 

    int* sizes = new int[n]; 
    for (int i = 0; i < n; i++) {
        cin >> sizes[i]; 
    }

    cout << fixprice(sizes, n); 

    delete[] sizes; 
    return 0; 
}