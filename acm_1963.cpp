/*
ACMICPC
문제 번호 : 1963
문제 제목 : 소수 경로
풀이 날짜 : 2020-05-06
Solved By Reamer
*/

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

bool isPrime[10000] = {0};
bool isPrimeVisit[10000] = {0};
int graph[10000] = {0};
bool isVisit[10000] = {0};

int main()
{
    int testCase;
    queue<int> intQ;

    int start, end;
    cin >> testCase;

    for (int i = 2; i < 10000; i++)
    {
        if (!isPrimeVisit[i])
        {
            isPrime[i] = true;
            for (int j = i + i; j < 10000; j += i)
            {
                isPrimeVisit[j] = true;
            }
        }
    }

    for (int i = 0; i < testCase; i++)
    {
        bool isFind = false;
        cin >> start >> end;
        intQ.push(start);
        isVisit[start] = true;
        while (!intQ.empty())
        {
            int num = intQ.front();
            intQ.pop();

            if (num == end)
            {
                isFind = true;
                break;
            }
            for (int j = 1; j <= 1000; j *= 10)
            {
                for (int k = 0; k < 10; k++)
                {
                    int keyNum = num / (10 * j) * (10 * j) + num % (1 * j) + k * j;
                    if (keyNum < 1000)
                        continue;
                    if (isPrime[keyNum] && !isVisit[keyNum])
                    {
                        intQ.push(keyNum);
                        isVisit[keyNum] = true;
                        graph[keyNum] = graph[num] + 1;
                    }
                }
            }
        }

        if (isFind)
            cout << graph[end] << endl;
        else
            cout << "Impossible" << endl;
        memset(isVisit, 0, sizeof(isVisit));
        memset(graph, 0, sizeof(graph));
        while (!intQ.empty())
        {
            intQ.pop();
        }
    }

    return 0;
}