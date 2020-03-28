/*
ACMICPC
문제 번호 : 5988
문제 제목 : 홀수일까 짝수일까
풀이 날짜 : 2020-03-28
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    string str;
    for (int i = 0; i < num; i++)
    {
        cin >> str;
        if (str.back() == '0' || str.back() == '2' || str.back() == '4' || str.back() == '6' || str.back() == '8')
            cout << "even" << endl;
        else
            cout << "odd" << endl;
    }
    return 0;
}