/*
ACMICPC
문제 번호 : 9012
문제 제목 : 괄호
풀이 날짜 : 2020-05-07
Solved By Reamer
*/

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int R, C;
    char graph[50][50];
    int isVisit[50][50] = {0};
    bool waterVisit[50][50] = {0};
    int water[50][50] = {0};
    queue<pair<int, int>> pairQ;
    queue<pair<int, int>> waterQ;
    string str;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> str;
        for (int j = 0; j < C; j++)
        {
            graph[i][j] = str[j];
            if (str[j] == 'S')
            {
                pairQ.push(make_pair(i, j));
                isVisit[i][j] = 1;
            }
            else if (str[j] == '*')
            {
                waterQ.push(make_pair(i, j));
                water[i][j] = 1;
                waterVisit[i][j] = true;
            }
        }
    }

    while (!waterQ.empty())
    {
        int x, y;
        tie(x, y) = waterQ.front();
        waterQ.pop();

        if (x - 1 >= 0 && graph[x - 1][y] == '.' && !waterVisit[x - 1][y])
        {
            waterQ.push(make_pair(x - 1, y));
            water[x - 1][y] = water[x][y] + 1;
            waterVisit[x - 1][y] = true;
        }
        if (y - 1 >= 0 && graph[x][y - 1] == '.' && !waterVisit[x][y - 1])
        {
            waterQ.push(make_pair(x, y - 1));
            water[x][y - 1] = water[x][y] + 1;
            waterVisit[x][y - 1] = true;
        }
        if (x + 1 < R && graph[x + 1][y] == '.' && !waterVisit[x + 1][y])
        {
            waterQ.push(make_pair(x + 1, y));
            water[x + 1][y] = water[x][y] + 1;
            waterVisit[x + 1][y] = true;
        }
        if (y + 1 < C && graph[x][y + 1] == '.' && !waterVisit[x][y + 1])
        {
            waterQ.push(make_pair(x, y + 1));
            water[x][y + 1] = water[x][y] + 1;
            waterVisit[x][y + 1] = true;
        }
    }

    int answer;
    bool isAnswer = false;
    while (!pairQ.empty())
    {
        int x, y;
        tie(x, y) = pairQ.front();
        pairQ.pop();
        if (graph[x][y] == 'D')
        {
            isAnswer = true;
            answer = isVisit[x][y];
            break;
        }

        if (x - 1 >= 0 && graph[x - 1][y] != '*' && graph[x - 1][y] != 'X' && !isVisit[x - 1][y] && (water[x - 1][y] == 0 || water[x - 1][y] > isVisit[x][y] + 1))
        {
            pairQ.push(make_pair(x - 1, y));
            isVisit[x - 1][y] = isVisit[x][y] + 1;
        }
        if (y - 1 >= 0 && graph[x][y - 1] != '*' && graph[x][y - 1] != 'X' && !isVisit[x][y - 1] && (water[x][y - 1] == 0 || water[x][y - 1] > isVisit[x][y] + 1))
        {
            pairQ.push(make_pair(x, y - 1));
            isVisit[x][y - 1] = isVisit[x][y] + 1;
        }
        if (x + 1 < R && graph[x + 1][y] != '*' && graph[x + 1][y] != 'X' && !isVisit[x + 1][y] && (water[x + 1][y] == 0 || water[x + 1][y] > isVisit[x][y] + 1))
        {
            pairQ.push(make_pair(x + 1, y));
            isVisit[x + 1][y] = isVisit[x][y] + 1;
        }
        if (y + 1 < C && graph[x][y + 1] != '*' && graph[x][y + 1] != 'X' && !isVisit[x][y + 1] && (water[x][y + 1] == 0 || water[x][y + 1] > isVisit[x][y] + 1))
        {
            pairQ.push(make_pair(x, y + 1));
            isVisit[x][y + 1] = isVisit[x][y] + 1;
        }
    }

    if (isAnswer)
        cout << answer - 1 << endl;
    else
        cout << "KAKTUS" << endl;

    return 0;
}
