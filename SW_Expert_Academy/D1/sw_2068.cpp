/*
난이도 : D1
문제 번호 : 2068
문제 제목 : 최대수 구하기
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
        for (int j = 0; j < 10; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(), intVec.end());
        cout << "#" << (i + 1) << " " << intVec.back() << endl;
        intVec.clear();
    }

    return 0;
}