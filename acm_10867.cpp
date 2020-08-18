/*
ACMICPC
문제 번호 : 10867
문제 제목 : 중복 빼고 정렬하기
풀이 날짜 : 2020-08-18
Solved By Reamer
*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, tmp;
    set<int, less<int>> intSet;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intSet.insert(tmp);
    }

    for (set<int>::iterator it = intSet.begin(); it != intSet.end(); it++)
        cout << *it << " ";
    return 0;
}