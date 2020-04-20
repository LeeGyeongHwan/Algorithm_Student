/*
ACMICPC
문제 번호 : 17263
문제 제목 : sort 마스터 배지훈
풀이 날짜 : 2020-04-20
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num, tmp;
    vector<int> intVec;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());
    cout << intVec.back() << endl;

    return 0;
}