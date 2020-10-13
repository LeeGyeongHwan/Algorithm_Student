/* 
ACMICPC
Study Group
10th Week
문제 번호 : 4485
문제 제목 : 녹색 옷 입은 애가 젤다지?
풀이 날짜 : 2020-10-13
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
#include <queue>
#include <tuple>

using namespace std;

int N;
int map[125][125], dp[125][125];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> pairQ;
    int problem = 0;
    int x, y;

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        memset(map, 0, sizeof(map));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                dp[i][j] = -1;
            }

        pairQ.push({0, 0});
        dp[0][0] = map[0][0];
        while (!pairQ.empty())
        {
            tie(x, y) = pairQ.front();
            pairQ.pop();
            if (x == N - 1 && y == N - 1)
                continue;
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX < 0 || newX >= N || newY < 0 || newY >= N)
                    continue;
                if (dp[newX][newY] == -1)
                {
                    dp[newX][newY] = dp[x][y] + map[newX][newY];
                    pairQ.push({newX, newY});
                }
                else if (dp[newX][newY] > dp[x][y] + map[newX][newY])
                {
                    dp[newX][newY] = dp[x][y] + map[newX][newY];
                    pairQ.push({newX, newY});
                }
            }
        }

        cout << "Problem " << ++problem << ": " << dp[N - 1][N - 1] << "\n";
    }

    return 0;
}