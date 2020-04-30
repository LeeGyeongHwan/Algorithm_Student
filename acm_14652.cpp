/*
ACMICPC
문제 번호 : 14652
문제 제목 : 나는 행복합니다~
풀이 날짜 : 2020-04-30
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int N, M, seat;

    cin>>N>>M>>seat;

    cout<<seat/M<<" "<<seat%M<<endl;

    return 0;
}