#include <iostream>

using namespace std;

int main()
{
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    //x // y // w- x// h-y
    int xmin = x > w - x ? w - x : x;
    int ymin = y > h - y ? h - y : y;
    int min = xmin > ymin ? ymin : xmin;
    cout << min << endl;

    return 0;
}