/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 9205
문제 제목 : 맥주 마시면서 걸어가기
풀이 날짜 : 2020-08-06
Solved By Reamer 
*/

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string.h>

using namespace std;

int main()
{
    int testCase, store;
    int startX, startY, tmpX, tmpY, destX, destY;
    vector<pair<int, int>> storeVec;
    queue<tuple<int, int, int>> tupleQ;
    bool isVisited[100];
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {

        cin >> store;
        cin >> startX >> startY;
        for (int j = 0; j < store; j++)
        {
            cin >> tmpX >> tmpY;
            storeVec.push_back(make_pair(tmpX, tmpY));
        }
        cin >> destX >> destY;

        tupleQ.push(make_tuple(startX, startY, 20));
        bool isPossible = false;
        while (!tupleQ.empty())
        {
            int x, y, beer;
            tie(x, y, beer) = tupleQ.front();
            tupleQ.pop();
            int difference = abs(destX - x) + abs(destY - y);
            if (difference / 50 < beer || (difference / 50 == beer && difference % 50 == 0))
            {
                isPossible = true;
                break;
            }

            for (int j = 0; j < store; j++)
            {
                if (!isVisited[j])
                {
                    int newX, newY;
                    tie(newX, newY) = storeVec[j];
                    int newDifference = abs(x - newX) + abs(y - newY);
                    if (newDifference / 50 < beer || (newDifference / 50 == beer && newDifference % 50 == 0))
                    {
                        isVisited[j] = true;
                        tupleQ.push(make_tuple(newX, newY, 20));
                    }
                }
            }
        }

        if (isPossible)
            cout << "happy\n";
        else
            cout << "sad\n";

        storeVec.clear();
        memset(isVisited, 0, sizeof(isVisited));
        while (!tupleQ.empty())
        {
            tupleQ.pop();
        }
    }
    return 0;
}