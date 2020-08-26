/*
ACMICPC
문제 번호 : 2352
문제 제목 : 반도체 설계
풀이 날짜 : 2020-08-26
Solved By Reamer
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> port;
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        auto it = lower_bound(port.begin(), port.end(), tmp);
        if (it == port.end())
            port.push_back(tmp);
        else
            *it = tmp;
    }
    cout << port.size() << "\n";
    return 0;
}