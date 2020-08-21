/* 
ACMICPC
Study Group
4th Week
문제 번호 : 10216
문제 제목 : Count Circle Groups
풀이 날짜 : 2020-08-21
Solved By Reamer 
*/

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<tuple<int, int, int>> tupleVec;
    queue<int> intQ;
    bool isVisited[3000];
    int testCase, enemy;
    int x, y, R, tmpX, tmpY, tmpR;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> enemy;
        for (int j = 0; j < enemy; j++)
        {
            cin >> x >> y >> R;
            tupleVec.push_back({x, y, R});
        }
        int group = 0;
        memset(isVisited, 0, sizeof(isVisited));

        for (int j = 0; j < enemy; j++)
        {
            if (!isVisited[j])
            {
                group++;
                intQ.push(j);
                while (!intQ.empty())
                {
                    int num = intQ.front();
                    intQ.pop();

                    for (int k = j + 1; k < enemy; k++)
                    {
                        if (isVisited[k])
                            continue;
                        tie(x, y, R) = tupleVec[num];
                        tie(tmpX, tmpY, tmpR) = tupleVec[k];
                        if ((tmpX - x) * (tmpX - x) + (tmpY - y) * (tmpY - y) <= (R + tmpR) * (R + tmpR))
                        {
                            isVisited[k] = true;
                            intQ.push(k);
                        }
                    }
                }
            }
        }
        cout << group << "\n";
        tupleVec.clear();
    }

    return 0;
}