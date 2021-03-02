/*
ACMICPC
문제 번호 : 2212
문제 제목 : 센서
풀이 날짜 : 2021-03-02
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K, sensor;
    vector<int> intVec, distVec;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> sensor;
        intVec.push_back(sensor);
    }
    if (N <= K)
    {
        cout << "0\n";
        return 0;
    }
    sort(intVec.begin(), intVec.end());
    int totalDistance = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int diff = intVec[i + 1] - intVec[i];
        totalDistance += diff;
        distVec.push_back(diff);
    }

    sort(distVec.begin(), distVec.end());
    for (int i = 0; i < K - 1; i++)
    {
        totalDistance -= distVec[N - 2 - i];
    }
    cout << totalDistance << endl;

    return 0;
}