/*
ACMICPC
문제 번호 : 10471
문제 제목 : 공간을 만들어 봅시다
풀이 날짜 : 2020-09-11
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool selected[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int W, P, num;
    vector<int> intVec;
    cin >> W >> P;

    intVec.push_back(0);
    for (int i = 0; i < P; i++)
    {
        cin >> num;
        intVec.push_back(num);
    }
    intVec.push_back(W);

    for (int i = 0; i < intVec.size() - 1; i++)
    {
        for (int j = i + 1; j < intVec.size(); j++)
        {
            selected[intVec[j] - intVec[i]] = true;
        }
    }
    for (int i = 0; i <= W; i++)
        if (selected[i])
            cout << i << " ";
    return 0;
}