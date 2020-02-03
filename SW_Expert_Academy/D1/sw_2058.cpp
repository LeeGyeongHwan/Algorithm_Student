/*
난이도 : D1
문제 번호 : 2058
문제 제목 : 자릿수 더하기
풀이 날짜 : 2020-02-03
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int num, sumNum = 0;
    cin >> num;
    do
    {
        sumNum += num % 10;
        num /= 10;
    } while (num != 0);

    cout << sumNum << endl;
    return 0;
}