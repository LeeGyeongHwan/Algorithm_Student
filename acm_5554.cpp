#include <iostream>
using namespace std;

int main()
{
    int time = 0;
    int tmp;
    for (int i = 0; i < 4; i++)
    {
        cin >> tmp;
        time += tmp;
    }
    cout << time / 60 << endl;
    cout << time % 60 << endl;
}