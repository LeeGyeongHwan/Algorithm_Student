/*
ACMICPC
문제 번호 : 10816
문제 제목 : 숫자 카드 2
풀이 날짜 : 2020-10-15
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
    cout.tie(NULL);
    int N, M, tmp;
    vector<int> intVec;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        auto beginIt = lower_bound(intVec.begin(), intVec.end(), tmp);
        auto endIt = upper_bound(intVec.begin(), intVec.end(), tmp);
        cout << endIt - beginIt << " ";
    }

    return 0;
}