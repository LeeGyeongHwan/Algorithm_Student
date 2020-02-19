/*
난이도 : D3
문제 번호 : 6913
문제 제목 : 동철이의 프로그래밍 대회
풀이 날짜 : 2020-02-19
Solved By Reamer
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, people, problem, tmp;
    vector<int> answerVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> people >> problem;

        for (int j = 0; j < people; j++)
        {
            int sum = 0;
            for (int k = 0; k < problem; k++)
            {
                cin >> tmp;
                sum += tmp;
            }
            answerVec.push_back(sum);
        }

        sort(answerVec.begin(), answerVec.end());
        int count = 0;
        for (int j = people - 1; j >= 0; j--)
        {
            if (answerVec[j] == answerVec.back())
                count++;
            else
                break;
        }
        cout << "#" << (i + 1) << " " << count << " " << answerVec.back() << "\n";
        answerVec.clear();
    }
    return 0;
}