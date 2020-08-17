/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 1507
문제 제목 : 궁금한 민호
풀이 날짜 : 2020-08-18
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int city[20][20] = {0};
int tmpCity[20][20] = {0};
int maxDist = 1000000;
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> city[i][j];
            tmpCity[i][j] = city[i][j];
        }
    }

    bool isAnswer = true;
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j || i == k || j == k)
                    continue;
                if (city[i][j] == city[i][k] + city[k][j])
                {
                    tmpCity[i][j] = maxDist;
                }
                else if (city[i][j] > city[i][k] + city[k][j])
                {
                    isAnswer = false;
                }
            }
        }
    }
    int dist = 0;
    if (isAnswer)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (tmpCity[i][j] != maxDist)
                    dist += tmpCity[i][j];
            }
        }
    }
    else
        dist = -1;
    cout << dist << "\n";

    return 0;
}