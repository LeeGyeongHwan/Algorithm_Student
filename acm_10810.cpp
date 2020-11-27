/* 
ACMICPC 
문제 번호 : 10810 
문제 제목 : 공 넣기
풀이 날짜 : 2020-11-28
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int ball[101];

int main()
{
    int N, M;
    int x, y, num;

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> num;
        for (int j = x; j <= y; j++)
        {
            ball[j] = num;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ball[i] << " ";
    return 0;
}