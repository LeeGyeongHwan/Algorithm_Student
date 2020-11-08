/* 
ACMICPC 
문제 번호 : 14492
문제 제목 : 부울행렬의 부울곱
풀이 날짜 : 2020-11-08
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int A[300][300], B[300][300];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmpCnt = 0;
            for (int k = 0; k < N; k++)
            {
                tmpCnt += A[i][k] * B[k][j];
            }
            if (tmpCnt != 0)
                cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}