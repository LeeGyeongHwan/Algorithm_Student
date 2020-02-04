/*
난이도 : D3
문제 번호 : 9280
문제 제목 : 진용이네 주차타워
풀이 날짜 : 2020-02-04
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int testCase, N, M, tmp;
    int isOccupied[101] = {0};
    vector<int> costVec, weightVec;
    queue<int> orderQueue, waitQueue;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int profit = 0;
        cin >> N >> M;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            costVec.push_back(tmp);
        }
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            weightVec.push_back(tmp);
        }
        for (int j = 0; j < 2 * M; j++)
        {
            cin >> tmp;
            orderQueue.push(tmp);
        }
        int leftNum = 0;
        while (!orderQueue.empty())
        {
            int order = orderQueue.front();
            orderQueue.pop();
            if (order > 0)
            {
                if (leftNum < N)
                {
                    isOccupied[leftNum] = order;
                    profit += costVec[leftNum] * weightVec[order - 1];
                    for (int j = leftNum + 1; j < N; j++)
                    {
                        if (isOccupied[j] == 0)
                        {
                            leftNum = j;
                            break;
                        }
                    }
                    if (isOccupied[leftNum] == order)
                        leftNum = N;
                }
                else
                {
                    waitQueue.push(order);
                }
            }
            else
            {
                int absNum = abs(order);
                int location = 0;
                for (int j = 0; j < N; j++)
                {
                    if (isOccupied[j] == absNum)
                    {
                        isOccupied[j] = 0;
                        location = j;
                        break;
                    }
                }

                if (!waitQueue.empty())
                {
                    int orderNum = waitQueue.front();
                    isOccupied[location] = orderNum;
                    waitQueue.pop();
                    profit += costVec[location] * weightVec[orderNum - 1];
                    leftNum = N;
                }
                else
                {
                    if (leftNum > location)
                        leftNum = location;
                }
            }
        }
        cout << "#" << (i + 1) << " " << profit << endl;

        memset(isOccupied, 0, sizeof(isOccupied));
        costVec.clear();
        weightVec.clear();
    }
    return 0;
}