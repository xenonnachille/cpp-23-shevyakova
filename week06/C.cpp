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
    string s1 = "hihihaha1";
    string s2 = "hihihaha2";
    cout << s1.compare(s2);
    return 0;
}