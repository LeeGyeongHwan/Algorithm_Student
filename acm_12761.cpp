/*
ACMICPC
문제 번호 : 12761
문제 제목 : 돌다리
풀이 날짜 : 2020-05-04
Solved By Reamer
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int bridge[100001] = {0};
    bool isVisit[100001] = {0};
    queue<int> intQ;

    int A, B;
    int N, M;

    cin >> A >> B >> N >> M;

    intQ.push(N);
    isVisit[N] = true;

    while (!intQ.empty())
    {
        int num = intQ.front();
        intQ.pop();

        if (num == M)
            break;

        if (num - 1 >= 0 && !isVisit[num - 1])
        {
            intQ.push(num - 1);
            isVisit[num - 1] = true;
            bridge[num - 1] = bridge[num] + 1;
        }
        if (num + 1 <= 100000 && !isVisit[num + 1])
        {
            intQ.push(num + 1);
            isVisit[num + 1] = true;
            bridge[num + 1] = bridge[num] + 1;
        }
        if (num - A >= 0 && !isVisit[num - A])
        {
            intQ.push(num - A);
            isVisit[num - A] = true;
            bridge[num - A] = bridge[num] + 1;
        }
        if (num - B >= 0 && !isVisit[num - B])
        {
            intQ.push(num - B);
            isVisit[num - B] = true;
            bridge[num - B] = bridge[num] + 1;
        }
        if (num + A <= 100000 && !isVisit[num + A])
        {
            intQ.push(num + A);
            isVisit[num + A] = true;
            bridge[num + A] = bridge[num] + 1;
        }
        if (num + B <= 100000 && !isVisit[num + B])
        {
            intQ.push(num + B);
            isVisit[num + B] = true;
            bridge[num + B] = bridge[num] + 1;
        }
        if (num * A <= 100000 && !isVisit[num * A])
        {
            intQ.push(num * A);
            isVisit[num * A] = true;
            bridge[num * A] = bridge[num] + 1;
        }
        if (num * B <= 100000 && !isVisit[num * B])
        {
            intQ.push(num * B);
            isVisit[num * B] = true;
            bridge[num * B] = bridge[num] + 1;
        }
    }

    cout << bridge[M] << endl;

    return 0;
}