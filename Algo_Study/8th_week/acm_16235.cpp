/* 
ACMICPC
Study Group
8th Week
문제 번호 : 16235
문제 제목 : 나무 재테크
풀이 날짜 : 2020-09-30
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <string.h>
#include <algorithm>

using namespace std;

deque<int> dq[11][11], tmpQ;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    int x, y, z;
    cin >> N >> M >> K;

    int nutrient[11][11];
    int map[11][11];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> nutrient[i][j];
            map[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        if(dq[x][y].size()==0)
            dq[x][y].push_back(z);
    }

    for (int i = 0; i < K; i++) //K년
    {
        //봄
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                bool dead = false;
                while (!dq[j][k].empty())
                {
                    int age = dq[j][k].front();
                    if (map[j][k] < age || dead)
                    {
                        map[j][k] += age / 2; //여름
                        dead = true;
                    }
                    else
                    {
                        map[j][k] -= age;
                        tmpQ.push_back(age + 1);
                    }
                    dq[j][k].pop_front();
                }
                map[j][k] += nutrient[j][k]; //겨울
                dq[j][k].swap(tmpQ);
            }
        }

        //가을
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                while (!dq[j][k].empty())
                {
                    int age = dq[j][k].front();
                    if (age % 5 == 0)
                    {
                        for (int m = 0; m < 8; m++)
                        {
                            int newX = j + dx[m];
                            int newY = k + dy[m];

                            if (newX <= 0 || newX > N || newY <= 0 || newY > N)
                                continue;
                            dq[newX][newY].push_front(1);
                        }
                    }
                    tmpQ.push_back(age);
                    dq[j][k].pop_front();
                }
                dq[j][k].swap(tmpQ);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cnt += dq[i][j].size();
    cout << cnt << "\n";

    return 0;
}