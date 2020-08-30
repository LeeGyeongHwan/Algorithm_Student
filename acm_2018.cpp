/*
ACMICPC
문제 번호 : 2018
문제 제목 : 수들의 합 5
풀이 날짜 : 2020-08-30
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    int start = 1, end = 1, sumNum = 0, cnt = 0;
    while (true)
    {
        if (sumNum >= N)
            sumNum -= start++;
        else if (end > N)
            break;
        else
            sumNum += end++;
        if (sumNum == N)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}