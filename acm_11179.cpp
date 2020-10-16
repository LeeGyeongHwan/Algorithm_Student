/*
ACMICPC
문제 번호 : 11179
문제 제목 : 2진수 뒤집기
풀이 날짜 : 2020-10-17
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int N;
    string str = "";
    cin >> N;
    int mul = 1;
    while (N >= mul)
        mul *= 2;
    mul /= 2;

    while (mul > 0)
    {
        int num = N / mul;
        N %= mul;
        if (num == 1)
            str += "1";
        else
            str += "0";
        mul /= 2;
    }
    int answer = 0;
    mul = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
            answer += mul;
        mul *= 2;
    }
    cout << answer << endl;

    return 0;
}