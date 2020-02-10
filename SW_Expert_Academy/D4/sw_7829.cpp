/*
난이도 : D4
문제 번호 : 7829
문제 제목 : 보물왕 태혁
풀이 날짜 : 2020-02-10
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

    int testCase, num, tmp, answer;
    vector<int> intVec;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(), intVec.end());
        if (intVec.size() % 2 == 0)
            answer = intVec.front() * intVec.back();
        else
            answer = intVec[intVec.size() / 2] * intVec[intVec.size() / 2];
        cout << "#" << (i + 1) << " " << answer << endl;
        intVec.clear();
    }
    return 0;
}
