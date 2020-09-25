/* 
ACMICPC 
문제 번호 : 17608
문제 제목 : 막대기
풀이 날짜 : 2020-09-25
Solved By Reamer 
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N, tmp;
    stack<int> intS;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        while (!intS.empty())
        {
            if (intS.top() <= tmp)
                intS.pop();
            else
                break;
        }
        intS.push(tmp);
    }
    cout << intS.size() << "\n";
    return 0;
}