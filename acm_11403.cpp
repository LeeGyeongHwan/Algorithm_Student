/* 
ACMICPC 
문제 번호 : 11403
문제 제목 : 경로 찾기
풀이 날짜 : 2020-05-02
Solved By Reamer 
*/

#include <iostream>
#include <string.h>

using namespace std;

int graph[100][100] = {0};
bool isVisit[100] = {0};
int N;

int DFS(int x, int y)
{
    int num = 0;
    
    if (x == y && isVisit[y])
        return 1;

    for (int i = 0; i < N; i++)
    {
        if (graph[x][i] == 1 && !isVisit[i])
        {
            isVisit[i] = true;
            num += DFS(i, y);
        }
    }

    return num;
}

int main()
{

    int tmp;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num = DFS(i, j);
            cout << num << " ";
            memset(isVisit, 0, sizeof(isVisit));
        }
        cout << endl;
    }

    return 0;
}