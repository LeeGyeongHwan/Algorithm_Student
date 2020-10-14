/* 
ACMICPC
Study Group
10th Week
문제 번호 : 2304
문제 제목 : 창고 다각형
풀이 날짜 : 2020-10-14
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int L, H;
    vector<pair<int, int>> pairVec;
    stack<pair<int, int>> pairS;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L >> H;
        pairVec.push_back({L, H});
    }
    sort(pairVec.begin(), pairVec.end());
    int sumNum = 0;
    for (int i = 0; i < N; i++)
    {
        if (pairS.empty())
            pairS.push(pairVec[i]);
        else
        {
            if (pairS.top().second < pairVec[i].second)
            {
                pair<int, int> removedPair = {-1, -1};
                while (!pairS.empty() && pairS.top().second < pairVec[i].second)
                {
                    removedPair = pairS.top();
                    pairS.pop();
                }
                if (pairS.empty())
                    sumNum += (pairVec[i].first - removedPair.first) * removedPair.second;
            }
            pairS.push(pairVec[i]);
        }
    }
    pair<int, int> prevPair = {-1, -1};
    while (!pairS.empty())
    {
        if (prevPair.first == -1)
        {
            prevPair = pairS.top();
            pairS.pop();
        }
        else
        {
            pair<int, int> curPair = pairS.top();
            pairS.pop();
            sumNum += (prevPair.first - curPair.first) * prevPair.second;
            prevPair = curPair;
        }
    }
    sumNum += prevPair.second;
    cout << sumNum << "\n";
    return 0;
}