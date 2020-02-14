/*
난이도 : D3
문제 번호 : 8500
문제 제목 : 극장 좌석
풀이 날짜 : 2020-02-14
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

    int testCase, num, tmp;
    vector<int> intVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int totalSeat = 0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(), intVec.end());

        for (int j = 0; j < num; j++)
        {
            totalSeat += intVec[j];
        }
        totalSeat += (num + intVec.back());

        cout << "#" << (i + 1) << " " << totalSeat << endl;
        intVec.clear();
    }
    return 0;
}