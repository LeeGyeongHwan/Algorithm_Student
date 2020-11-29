/*
ACMICPC
문제 번호 : 11931
문제 제목 : 수 정렬하기 4
풀이 날짜 : 2020-11-30
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, tmp;
    vector<int> intVec;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());
    for (int i = N - 1; i >= 0; i--)
        cout << intVec[i] << "\n";

    return 0;
}