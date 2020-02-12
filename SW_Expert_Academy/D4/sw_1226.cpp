/*
난이도 : D4
문제 번호 : 1226
문제 제목 : 미로1
풀이 날짜 : 2020-02-12
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    string str;
    vector<vector<char>> charVV;
    vector<char> tmpVec;
    bool isVisited[16][16] = {0};
    pair<int, int> start, destination;
    queue<pair<int, int>> pairQ;
    for (int i = 0; i < 10; i++)
    {
        bool isRoute = false;
        cin >> testCase;
        for (int j = 0; j < 16; j++)
        {
            cin >> str;
            for (int k = 0; k < 16; k++)
            {
                tmpVec.push_back(str[k]);
                if (str[k] == '2')
                    start = make_pair(k, j);
                else if (str[k] == '3')
                    destination = make_pair(k, j);
            }
            charVV.push_back(tmpVec);
            tmpVec.clear();
        }
        pairQ.push(start);
        isVisited[start.first][start.second] = true;

        while (!pairQ.empty())
        {
            int x = pairQ.front().first;
            int y = pairQ.front().second;
            pairQ.pop();
            if (x == destination.first && y == destination.second)
            {
                isRoute = true;
                break;
            }

            if (!isVisited[x - 1][y] && charVV[x - 1].at(y) != '1')
            {
                pairQ.push(make_pair(x - 1, y));
                isVisited[x - 1][y] = true;
            }
            if (!isVisited[x + 1][y] && charVV[x + 1].at(y) != '1')
            {
                pairQ.push(make_pair(x + 1, y));
                isVisited[x + 1][y] = true;
            }
            if (!isVisited[x][y - 1] && charVV[x].at(y - 1) != '1')
            {
                pairQ.push(make_pair(x, y - 1));
                isVisited[x][y - 1] = true;
            }
            if (!isVisited[x][y + 1] && charVV[x].at(y + 1) != '1')
            {
                pairQ.push(make_pair(x, y + 1));
                isVisited[x][y + 1] = true;
            }
        }

        cout << "#" << testCase << " " << isRoute << endl;
        while (!pairQ.empty())
        {
            pairQ.pop();
        }
        charVV.clear();
        memset(isVisited, 0, sizeof(isVisited));
    }
    return 0;
}
