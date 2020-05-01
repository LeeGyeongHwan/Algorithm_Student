/* 
ACMICPC 
문제 번호 : 11724
문제 제목 : 연결 요소의 개수
풀이 날짜 : 2020-05-01
Solved By Reamer 
*/

#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001] = {0};
bool isVisit[1001] = {0};
int main()
{
    int answer = 0;
    int N, M;
    int x, y;
    queue<int> intQ;

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        int num = i;
        if (!isVisit[num])
        {
            answer++;
            intQ.push(num);
            isVisit[num] = true;

            while (!intQ.empty())
            {
                int vertex = intQ.front();
                intQ.pop();
                for (int j = 1; j <= N; j++)
                {
                    if (graph[vertex][j] == 1 && !isVisit[j])
                    {
                        isVisit[j] = true;
                        intQ.push(j);
                    }
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}