/*
난이도 : D2
문제 번호 : 1966
문제 제목 : 숫자를 정렬하자
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N, tmp;
    vector<int> intVec;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(), intVec.end());
        cout << "#" << (i + 1);
        for (int j = 0; j < N; j++)
        {
            cout << " " << intVec[j];
        }
        cout << endl;
        intVec.clear();
    }

    return 0;
}