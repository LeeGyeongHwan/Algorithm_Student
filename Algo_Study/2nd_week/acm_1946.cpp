/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 1946
문제 제목 : 신입 사원
풀이 날짜 : 2020-08-07
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
    int testCase, candidate;
    int docu, interview;
    vector<pair<int, int>> pairVec;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> candidate;
        for (int j = 0; j < candidate; j++)
        {
            cin >> docu >> interview;
            pairVec.push_back(make_pair(docu, interview));
        }
        sort(pairVec.begin(), pairVec.end());

        int count = 1;
        int minScore = pairVec.front().second;
        for (int j = 1; j < pairVec.size(); j++)
        {
            if (pairVec[j].second < minScore)
            {
                minScore = pairVec[j].second;
                count++;
            }

            if (minScore == 1)
                break;
        }
        cout << count << "\n";
        pairVec.clear();
    }

    return 0;
}