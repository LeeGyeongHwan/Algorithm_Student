/*
ACMICPC
문제 번호 : 1644
문제 제목 : 소수의 연속합
풀이 날짜 : 2020-08-30
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;
bool isSelected[4000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 2; i <= 4000000; i++)
    {
        if (!isSelected[i])
        {
            prime.push_back(i);
            for (int j = i + i; j <= 4000000; j += i)
            {
                isSelected[j] = true;
            }
        }
    }

    int start = 0, end = 0, sumNum = 0, cnt = 0;

    while (true)
    {
        if (sumNum >= N)
            sumNum -= prime[start++];
        else if (prime[end] > N || end >= prime.size())
            break;
        else
            sumNum += prime[end++];

        if (sumNum == N)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}