/*
난이도 : D4
문제 번호 : 1211
문제 제목 : Ladder2
풀이 날짜 : 2020-02-01
Solved By Reamer
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, tmp;
    int ladder[100][100] = {0};
    vector<int> startVec;

    for (int i = 0; i < 10; i++)
    {
        cin >> testCase;
        pair<int, int> xy;
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                cin >> tmp;
                ladder[j][k] = tmp;
                if (j == 0 && tmp == 1)
                    startVec.push_back(k);
            }
        }
        pair<int, int> shortestPath = make_pair(10000, 0);

        for (int j = 0; j < startVec.size(); j++)
        {
            int isRight = 0;
            int isLeft = 0;
            xy = make_pair(0, startVec[j]);
            int distance = 0;
            while (xy.first < 99)
            {
                int x = xy.first;
                int y = xy.second;
                if (y - 1 >= 0 && ladder[x][y - 1] == 1 && !isRight)
                {
                    xy.second = y - 1;
                    isRight = 0;
                    isLeft = 1;
                }
                else if (y + 1 <= 99 && ladder[x][y + 1] == 1 && !isLeft)
                {
                    xy.second = y + 1;
                    isRight = 1;
                    isLeft = 0;
                }
                else
                {
                    xy.first = x + 1;
                    isRight = 0;
                    isLeft = 0;
                }
                distance++;
            }
            if (shortestPath.first >= distance)
            {
                shortestPath.first = distance;
                shortestPath.second = startVec[j];
            }
        }

        cout << "#" << testCase << " " << shortestPath.second << endl;
        memset(ladder, 0, sizeof(ladder));
        startVec.clear();
    }
    return 0;
}
