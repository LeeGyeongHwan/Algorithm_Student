/* 
ACMICPC 
문제 번호 : 2644
문제 제목 : 촌수계산
풀이 날짜 : 2020-05-03
Solved By Reamer 
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int graph[101][101] = {0};
    int isVisit[101] = {0};
    int N, M;
    int X, Y;
    int tmpX, tmpY;
    bool isRelated = false;
    queue<int> intQ;

    cin >> N;
    cin >> X >> Y;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> tmpX >> tmpY;
        graph[tmpX][tmpY] = 1;
        graph[tmpY][tmpX] = 1;
    }

    intQ.push(X);
    isVisit[X] = true;
    while (!intQ.empty())
    {
        int num = intQ.front();
        intQ.pop();
        if (num == Y)
        {
            isRelated = true;
            break;
        }

        for (int i = 1; i <= N; i++)
        {
            if (graph[num][i] == 1 && !isVisit[i])
            {
                intQ.push(i);
                isVisit[i] = isVisit[num] + 1;
            }
        }
    }

    if (isRelated)
        cout << isVisit[Y] - 1 << endl;
    else
        cout << "-1" << endl;

    return 0;
}