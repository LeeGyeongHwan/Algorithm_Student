/* 
ACMICPC 
문제 번호 : 2167
문제 제목 : 2차원 배열의 합
풀이 날짜 : 2020-06-04
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int N, M, K, num;
    int x1, y1, x2, y2;
    int graph[301][301] = {0};
    int sumGraph[301][301] = {0};

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> num;
            graph[i][j] = num;
            sumGraph[i][j] = sumGraph[i - 1][j] + sumGraph[i][j - 1] + num - sumGraph[i - 1][j - 1];
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sumGraph[x2][y2] - sumGraph[x1 - 1][y2] - sumGraph[x2][y1 - 1] + sumGraph[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}