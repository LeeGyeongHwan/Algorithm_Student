/*
ACMICPC
문제 번호 : 17406
문제 제목 : 배열 돌리기 4
풀이 날짜 : 2020-08-12
Solved By Reamer
*/

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[51][51] = {0};
    int tmpArr[51][51] = {0};
    vector<tuple<int, int, int>> tupleV;
    vector<int> perVec;
    int N, M, K;
    int r, c, s;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int startX, startY;
    int destX, destY;
    int tmpX, tmpY;

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        cin >> r >> c >> s;
        tupleV.push_back(make_tuple(r, c, s));
        perVec.push_back(i);
    }
    int minRow = 500000;
    do
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                tmpArr[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < perVec.size(); i++)
        {
            //회전
            int x, y, z;

            tie(x, y, z) = tupleV[perVec[i]];
            startX = x - z;
            startY = y - z;
            destX = x + z;
            destY = y + z;

            while (startX < destX && startY < destY)
            {
                int way = 0;
                tmpX = startX;
                tmpY = startY;
                int tmp = tmpArr[startX][startY];
                while (true)
                {
                    int newX = tmpX + dx[way];
                    int newY = tmpY + dy[way];

                    if (newX == startX && newY == startY)
                    {
                        break;
                    }
                    if (!(newX >= startX && newX <= destX && newY >= startY && newY <= destY))
                    {
                        way++;
                        newX = tmpX + dx[way];
                        newY = tmpY + dy[way];
                    }
                    // cout << "newx: " << newX << ", newY: " << newY << endl;
                    tmpArr[tmpX][tmpY] = tmpArr[newX][newY];
                    tmpX = newX;
                    tmpY = newY;
                }
                if (startY + 1 <= destY)
                    tmpArr[startX][startY + 1] = tmp;
                startX++;
                destX--;
                startY++;
                destY--;
            }
        }
        //row탐색
        for (int i = 1; i <= N; i++)
        {
            int sumRow = 0;
            for (int j = 1; j <= M; j++)
            {
                sumRow += tmpArr[i][j];
            }
            if (sumRow < minRow)
                minRow = sumRow;
        }

    } while (next_permutation(perVec.begin(), perVec.end()));

    cout << minRow << endl;
    return 0;
}