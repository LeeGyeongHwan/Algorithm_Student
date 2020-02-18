/*
난이도 : D3
문제 번호 : 4466
문제 제목 : 최대 성적표 만들기
풀이 날짜 : 2020-02-18
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

    int testCase, N, K, tmp;
    vector<int> intVec;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int sum = 0;
        cin >> N >> K;

        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        sort(intVec.begin(), intVec.end());

        for (int j = N - 1; j > N - 1 - K; j--)
            sum += intVec[j];

        cout << "#" << (i + 1) << " " << sum << endl;
        intVec.clear();
    }

    return 0;
}