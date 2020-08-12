/*
ACMICPC
문제 번호 : 1926
문제 제목 : 그림
풀이 날짜 : 2020-08-12
Solved By Reamer
*/

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int paint[500][500];
    bool isVisited[500][500] = {0};
    int N, M;
    queue<pair<int, int>> pairQ;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> paint[i][j];
        }
    }
    int paintNum = 0;
    int maxPaint = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!isVisited[i][j] && paint[i][j] == 1)
            {
                paintNum++;
                pairQ.push(make_pair(i, j));
                isVisited[i][j] = true;
                int paintSize = 0;
                while (!pairQ.empty())
                {
                    int x, y;
                    tie(x, y) = pairQ.front();
                    pairQ.pop();
                    paintSize++;
                    for (int k = 0; k < 4; k++)
                    {
                        int newX = x + dx[k];
                        int newY = y + dy[k];

                        if (newX >= 0 && newX < N && newY >= 0 && newY < M && !isVisited[newX][newY])
                        {
                            if (paint[newX][newY] == 1)
                            {
                                isVisited[newX][newY] = true;
                                pairQ.push(make_pair(newX, newY));
                            }
                        }
                    }
                }

                if (paintSize > maxPaint)
                    maxPaint = paintSize;
            }
        }
    }
    cout << paintNum << "\n"
         << maxPaint << "\n";
}