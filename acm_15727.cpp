/*
ACMICPC
문제 번호 : 15727
문제 제목 : 조별과제를 하려는데 조장이 사라졌다
풀이 날짜 : 2020-04-13
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    cout << num / 5 + bool(num % 5) << endl;
    return 0;
}