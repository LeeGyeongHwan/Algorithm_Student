/*
난이도 : D4
문제 번호 : 6719
문제 제목 : 성수의 프로그래밍 강좌 시청
풀이 날짜 : 2020-03-09
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

    int testCase, lecture, maxLecture, tmp;
    vector<int> intVec;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        float answer = 0;
        cin >> lecture >> maxLecture;
        for (int j = 0; j < lecture; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(), intVec.end());
        for (int j = lecture - maxLecture; j < lecture; j++)
        {
            answer = (intVec[j] + answer) / 2;
        }
        cout << fixed;
        cout.precision(6);
        cout << "#" << (i + 1) << " " << answer << "\n";
        intVec.clear();
    }

    return 0;
}