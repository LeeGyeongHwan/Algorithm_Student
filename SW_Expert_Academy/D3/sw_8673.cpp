/*
난이도 : D3
문제 번호 : 8673
문제 제목 : 코딩 토너먼트1
풀이 날짜 : 2020-02-10
Solved By Reamer
*/

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, K, tmp, numA, numB;
    queue<int> intQueue;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int boringScore = 0;
        cin >> K;
        int test = pow(2, K);
        for (int j = 0; j < test; j++)
        {
            cin >> tmp;
            intQueue.push(tmp);
        }

        while (intQueue.size() != 1)
        {
            numA = intQueue.front();
            intQueue.pop();
            numB = intQueue.front();
            intQueue.pop();

            if (numA > numB)
            {
                boringScore += numA - numB;
                intQueue.push(numA);
            }
            else
            {
                boringScore += numB - numA;
                intQueue.push(numB);
            }
        }

        cout << "#" << (i + 1) << " " << boringScore << "\n";
        while(!intQueue.empty())
        {
            intQueue.pop();
        }
    }
    return 0;
}