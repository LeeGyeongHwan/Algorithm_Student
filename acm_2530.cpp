#include <iostream>

using namespace std;

int main()
{
    int hour, min, sec;
    int timeforcook;
    cin >> hour >> min >> sec >> timeforcook;

    sec += timeforcook;
    if (sec >= 60)
    {
        min += (sec / 60);
        sec %= 60;
    }
    if (min >= 60)
    {
        hour += (min / 60);
        min %= 60;
    }
    if (hour >= 24)
    {
        hour %= 24;
    }
    cout << hour << " " << min << " " << sec << endl;
    return 0;
}