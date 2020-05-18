/* 
ACMICPC 
문제 번호 : 2606
문제 제목 : 바이러스
풀이 날짜 : 2020-05-18
*/

#include <iostream>
#include <queue>

using namespace std;

int graph[101][101] = {0};
int isVisit[101] = {0};

int main()
{
    int computer, N;
    int X, Y;
    int answer = 0;
    queue<int> intQ;

    cin >> computer >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> X >> Y;
        graph[X][Y] = 1;
        graph[Y][X] = 1;
    }

    intQ.push(1);
    isVisit[1] = true;

    while (!intQ.empty())
    {
        int num = intQ.front();
        intQ.pop();

        for (int i = 1; i <= computer; i++)
        {
            if (graph[num][i] && !isVisit[i])
            {
                isVisit[i] = true;
                intQ.push(i);
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
