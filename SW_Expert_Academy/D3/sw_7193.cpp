/*
난이도 : D3
문제 번호 : 7193
문제 제목 : 승현이의 수학공부
풀이 날짜 : 2020-02-19
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N;
    string longNum;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> N >> longNum;
        int answer = 0;
        for (int j = 0; j < longNum.size(); j++)
        {
            answer += (int)(longNum[j] - '0') % (N - 1);
        }
        cout << "#" << (i + 1) << " " << answer % (N - 1) << "\n";
    }
    return 0;
}