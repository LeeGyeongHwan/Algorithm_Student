/* 
ACMICPC
Study Group
11th Week
문제 번호 : 10159
문제 제목 : 저울 
풀이 날짜 : 2020-10-20
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr1[101][101], arr2[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    int A, B;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            arr1[i][j] = 1000000;
            arr2[i][j] = 1000000;
        }

    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        arr1[A][B] = 1;
        arr2[B][A] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                    continue;
                arr1[i][j] = min(arr1[i][k] + arr1[k][j], arr1[i][j]);
                arr2[i][j] = min(arr2[i][k] + arr2[k][j], arr2[i][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            if (arr1[i][j] != 1000000 || arr2[i][j] != 1000000)
                sum++;
        }
        cout << N - sum - 1 << "\n";
    }

    return 0;
}