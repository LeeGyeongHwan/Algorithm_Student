/* 
ACMICPC 
문제 번호 : 2583
문제 제목 : 영역 구하기
풀이 날짜 : 2020-05-02
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int graph[100][100] = {0};
int isVisit[100][100] = {0};
int M, N;

int DFS(int x, int y)
{
    int num = 1;
    isVisit[x][y] = true;

    if (x - 1 >= 0 && graph[x - 1][y] == 0 && !isVisit[x - 1][y])
        num += DFS(x - 1, y);
    if (x + 1 < M && graph[x + 1][y] == 0 && !isVisit[x + 1][y])
        num += DFS(x + 1, y);
    if (y - 1 >= 0 && graph[x][y - 1] == 0 && !isVisit[x][y - 1])
        num += DFS(x, y - 1);
    if (y + 1 < N && graph[x][y + 1] == 0 && !isVisit[x][y + 1])
        num += DFS(x, y + 1);
    return num;
}

int main()
{
    int K;
    int x1, y1, x2, y2;
    vector<int> area;
    int count = 0;
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++)
        {
            for (int k = x1; k < x2; k++)
            {
                graph[j][k] = 1;
            }
        }
    }
    

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == 0 && !isVisit[i][j])
            {
                count++;
                int num = DFS(i, j);
                area.push_back(num);
            }
        }
    }
    sort(area.begin(), area.end());
    cout << count << endl;

    for (int i = 0; i < area.size(); i++)
    {
        cout << area[i] << " ";
    }
    return 0;
}