/* 
ACMICPC 
문제 번호 : 2667
문제 제목 : 단지번호붙이기
풀이 날짜 : 2020-05-01
Solved By Reamer 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int graph[25][25] = {0};
bool isVisit[25][25] = {0};

int dfs(int x, int y, int N)
{
    isVisit[x][y] = true;
    int sumDFS = 1;

    if (x - 1 >= 0 && !isVisit[x - 1][y] && graph[x - 1][y])
        sumDFS += dfs(x - 1, y, N);
    if (y - 1 >= 0 && !isVisit[x][y - 1] && graph[x][y - 1])
        sumDFS += dfs(x, y - 1, N);
    if (x + 1 < N && !isVisit[x + 1][y] && graph[x + 1][y])
        sumDFS += dfs(x + 1, y, N);
    if (y + 1 < N && !isVisit[x][y + 1] && graph[x][y + 1])
        sumDFS += dfs(x, y + 1, N);

    return sumDFS;
}

int main()
{
    int N;
    int count = 0;
    vector<int> intVec;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = (int)(str[j] - '0');
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] != 0 && !isVisit[i][j])
            {
                count++;
                int num = dfs(i, j, N);
                intVec.push_back(num);
            }
        }
    }

    sort(intVec.begin(), intVec.end());

    cout << count << endl;
    for (int i = 0; i < intVec.size(); i++)
        cout << intVec[i] << endl;

    return 0;
}