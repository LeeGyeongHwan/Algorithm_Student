/*
ACMICPC
문제 번호 : 6198
문제 제목 : 옥상 정원 꾸미기
풀이 날짜 : 2020-08-23
Solved By Reamer
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N, height;
    stack<int> intS;
    cin >> N;
    long long cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> height;
        while (!intS.empty())
        {
            if (intS.top() <= height)
                intS.pop();
            else
                break;
        }
        cnt += intS.size();
        intS.push(height);
    }
    cout << cnt << "\n";

    return 0;
}