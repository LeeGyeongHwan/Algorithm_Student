/* 
ACMICPC
Study Group
7th Week
문제 번호 : 14500
문제 제목 : 테트로미노
풀이 날짜 : 2020-09-23
Solved By Reamer 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tetro[] = {{{1, 1, 1, 1}}, {{1}, {1}, {1}, {1}}, {{1, 1}, {1, 1}}, {{1, 0}, {1, 0}, {1, 1}}, {{0, 0, 1}, {1, 1, 1}}, {{1, 1}, {0, 1}, {0, 1}}, {{1, 1, 1}, {1, 0, 0}}, {{0, 1}, {0, 1}, {1, 1}}, {{1, 1, 1}, {0, 0, 1}}, {{1, 1}, {1, 0}, {1, 0}}, {{1, 0, 0}, {1, 1, 1}}, {{1, 0}, {1, 1}, {0, 1}}, {{0, 1, 1}, {1, 1, 0}}, {{0, 1}, {1, 1}, {1, 0}}, {{1, 1, 0}, {0, 1, 1}}, {{1, 1, 1}, {0, 1, 0}}, {{1, 0}, {1, 1}, {1, 0}}, {{0, 1, 0}, {1, 1, 1}}, {{0, 1}, {1, 1}, {0, 1}}};

int N, M;
int map[500][500];
int maxSum = 0;

void findCase(int x, int y)
{

    for (int i = 0; i < 19; i++)
    {
        int R = tetro[i].size();
        int C = tetro[i].front().size();
        int sum = 0;
        if (!(x + R <= N && y + C <= M))
            continue;
        for (int j = 0; j < R; j++)
            for (int k = 0; k < C; k++)
                sum += map[x + j][y + k] * tetro[i][j][k];
        if (maxSum < sum)
            maxSum = sum;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            findCase(i, j);

    cout << maxSum << "\n";
    return 0;
}