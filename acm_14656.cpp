/*
ACMICPC
문제 번호 : 14656
문제 제목 : 조교는 새디스트야!!
풀이 날짜 : 2020-03-25
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int num, tmp;
    int count = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        if ((i + 1) != tmp)
            count++;
    }
    cout << count << endl;
    return 0;
}