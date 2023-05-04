#include <iostream> 

using std::cin;
using std::endl;
using std::cout;
using std::string; 
 
int main() { 
    string str1, str2; 
    cin >> str1 >> str2; 
    int len1 = str1.length(), len2 = str2.length(); 
    int** arr = new int*[len1 + 1]; 

    for (int i = 0; i <= len1; i++) { 
        arr[i] = new int[len2 + 1]; 
        for (int j = 0; j <= len2; j++) { 
            if (i == 0 or j == 0) { 
                arr[i][j] = 0; 
            } 
            else if (str1[i - 1] == str2[j - 1]) { 
                arr[i][j] = arr[i - 1][j - 1] + 1;
            } 
            else {
                arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]); 
            } 
        } 
    } 
    
    cout << 100 * arr[len1][len2] / std::min(len1, len2);

    for (int i = 0; i <= len1; i++) { 
        delete[] arr[i]; 
    } 
    delete[] arr; 
    return 0; 
}