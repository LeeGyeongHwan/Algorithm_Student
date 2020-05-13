/* 
ACMICPC 
문제 번호 : 1388
문제 제목 : 바닥 장식
풀이 날짜 : 2020-05-13
Solved By Reamer 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, M;
    char graph[100][100] = {0};
    bool isVisit[100][100] = {0};
    string str;
    int answer = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = str[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(!isVisit[i][j])
            {
                isVisit[i][j]=true;
                if (graph[i][j] == '-')
                {
                    for (int k = j + 1; k < M; k++)
                    {
                        if (graph[i][k] == graph[i][j])
                        {
                            isVisit[i][k] = true;
                        }
                        else
                            break;
                    }
                }
                else
                {
                    for (int k = i + 1; k < N; k++)
                    {
                        if (graph[k][j] == graph[i][j])
                        {
                            isVisit[k][j] = true;
                        }
                        else
                            break;
                    }
                }
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}