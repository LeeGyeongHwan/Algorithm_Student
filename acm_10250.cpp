#include <iostream>

using namespace std;

int main()
{
    int T;
    int H, W, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> H >> W >> N;
        int floor;
        int room;
        if (N % H == 0)
        {
            room = H;
            floor = N / H;
        }
        else
        {
            room = N % H;
            floor = N / H + 1;
        }

        cout << room * 100 + floor << endl;
    }

    return 0;
}