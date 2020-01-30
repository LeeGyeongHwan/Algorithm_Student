#include <iostream>

using namespace std;

int main()
{
    int N, M, x, y;
    bool isFriend[1001][1001] = {false};

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        isFriend[x][y] = true;
        isFriend[y][x] = true;
    }

    for (int i = 1; i <= N; i++)
    {
        int sumFriend = 0;
        for (int j = 0; j <= N; j++)
        {
            if (isFriend[i][j])
                sumFriend++;
        }
        cout << sumFriend << endl;
    }

    return 0;
}