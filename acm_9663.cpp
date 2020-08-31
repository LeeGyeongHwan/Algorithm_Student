/* 
ACMICPC 
문제 번호 : 9663
문제 제목 : N-Queen
풀이 날짜 : 2020-08-31
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int N;
int queen[16];
int answer = 0;

bool check(int num)
{
    for (int i = 1; i < num; i++)
    {
        if ((queen[i] == queen[num]) || (abs(queen[i] - queen[num]) == num - i))
            return false;
    }

    return true;
}

void setQueen(int num)
{
    if (num > N)
    {
        answer++;
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        queen[num] = i;
        if (check(num))
            setQueen(num + 1);
    }
}

int main()
{
    cin >> N;
    setQueen(1);
    cout << answer << "\n";
    return 0;
}