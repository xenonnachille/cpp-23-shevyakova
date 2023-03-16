#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time t_0, t_k, dt;
    cin >> t_0.hours >> t_0.minutes >> t_0.seconds >> dt.hours >> dt.minutes >> dt.seconds;
    t_k.seconds = (t_0.seconds + dt.seconds) % 60;
    t_k.minutes = (t_0.minutes + dt.minutes + (t_0.seconds + dt.seconds) / 60) % 60;
    t_k.hours   = (t_0.hours + dt.hours + (t_0.minutes + dt.minutes + (t_0.seconds + dt.seconds) / 60) / 60) % 24;

    cout << t_k.hours << ':' << t_k.minutes << ':' << t_k.seconds << endl;

    return 0;
}