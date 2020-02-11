/*
난이도 : D3
문제 번호 : 8338
문제 제목 : 계산기 
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <math.h>
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
        int answer;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        answer = intVec.front();
        for (int j = 1; j < N; j++)
        {
            if (answer == 0 || answer == 1 || intVec[j] == 0 || intVec[j] == 1)
                answer += intVec[j];
            else
                answer *= intVec[j];
        }
        cout << "#" << (i + 1) << " " << answer << "\n";
        intVec.clear();
    }
    return 0;
}