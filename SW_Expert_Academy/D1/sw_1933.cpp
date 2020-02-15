/*
난이도 : D1
문제 번호 : 1933
문제 제목 : 간단한 N 의 약수
풀이 날짜 : 2020-02-15
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cout << i << " ";
    }
    return 0;
}