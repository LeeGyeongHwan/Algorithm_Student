/*
난이도 : D1
문제 번호 : 2063
문제 제목 : 중간값 찾기
풀이 날짜 : 2020-02-03
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int testCase, tmp;
    vector<int> intVec;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());
    cout << intVec[testCase / 2] << endl;

    return 0;
}