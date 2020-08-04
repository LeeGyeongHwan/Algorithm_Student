/*
ACMICPC
문제 번호 : 12738
문제 제목 : 가장 긴 증가하는 부분 수열 3
풀이 날짜 : 2020-08-04
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, tmp;
    cin >> N;
    vector<int> intVec;
    vector<int>::iterator it;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        it = lower_bound(intVec.begin(), intVec.end(), tmp);
        if (it == intVec.end())
            intVec.push_back(tmp);
        else
            *it = tmp;
    }

    cout << intVec.size() << endl;

    return 0;
}