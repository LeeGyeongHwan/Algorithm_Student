/*
ACMICPC
문제 번호 : 1158
문제 제목 : 요세푸스 문제
풀이 날짜 : 2020-10-25
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> intVec;

    for (int i = 1; i <= N; i++)
        intVec.push_back(i);

    int cnt = 0;
    int idx = K - 1;
    cout << "<";
    while (cnt != N - 1)
    {
        cout << intVec[idx] << ", ";
        intVec.erase(intVec.begin() + idx);
        cnt++;
        idx = (idx + K - 1) % (N - cnt);
    }
    cout << intVec[idx] << ">\n";

    return 0;
}