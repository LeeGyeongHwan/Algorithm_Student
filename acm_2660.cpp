/* 
ACMICPC 
문제 번호 : 2660
문제 제목 : 회장뽑기
풀이 날짜 : 2020-08-05
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> A, pair<int, int> B)
{
    if (A.first < B.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int N, from, to;
    int maxNum = 100;
    int member[51][51];
    vector<pair<int, int>> pairVec;
    vector<int> answerVec;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                member[i][j] = 0;
                continue;
            }
            member[i][j] = maxNum;
        }
    }
    while (true)
    {
        cin >> from >> to;
        if (from == -1 && to == -1)
            break;
        member[from][to] = member[to][from] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                member[i][j] = min(member[i][j], member[i][k] + member[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int maxNum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (maxNum < member[i][j])
                maxNum = member[i][j];
        }
        pairVec.push_back(make_pair(maxNum, i));
    }
    sort(pairVec.begin(), pairVec.end(), compare);

    for (int i = 0; i < pairVec.size(); i++)
    {
        if (pairVec[i].first == pairVec.front().first)
        {
            answerVec.push_back(pairVec[i].second);
        }
    }
    sort(answerVec.begin(), answerVec.end());
    cout << pairVec.front().first << " " << answerVec.size() << endl;
    for (int i = 0; i < answerVec.size(); i++)
        cout << answerVec[i] << " ";
    return 0;
}