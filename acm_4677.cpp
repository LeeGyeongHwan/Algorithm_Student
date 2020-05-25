/* 
ACMICPC 
문제 번호 : 4677
문제 제목 : Oil Deposits
풀이 날짜 : 2020-05-25
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char graph[100][100];
bool isVisit[100][100] = {0};

int m, n;
int wayX[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int wayY[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void DFS(int x, int y)
{
    isVisit[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        int tmpX = x + wayX[i];
        int tmpY = y + wayY[i];
        if (!(tmpX >= 0 && tmpX < m && tmpY >= 0 && tmpY < n))
            continue;
        if (graph[tmpX][tmpY] == '@' && !isVisit[tmpX][tmpY])
            DFS(tmpX, tmpY);
    }
}

int main()
{

    string str;

    while (1)
    {
        cin >> m >> n;
        if (m == 0)
            break;
        int answer = 0;

        for (int i = 0; i < m; i++)
        {
            cin >> str;
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = str[j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] == '@' && !isVisit[i][j])
                {
                    DFS(i, j);
                    answer++;
                }
            }
        }
        cout << answer << endl;
        memset(isVisit, 0, sizeof(isVisit));
    }

    return 0;
}