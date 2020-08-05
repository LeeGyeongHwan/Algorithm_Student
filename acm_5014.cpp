/*
ACMICPC
문제 번호 : 5014
문제 제목 : 스타트링크
풀이 날짜 : 2020-08-05
Solved By Reamer
*/

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
    int F, S, G, U, D;
    queue<pair<int, int>> intQ;
    bool isVisit[1000001] = {0};
    cin >> F >> S >> G >> U >> D;

    intQ.push(make_pair(S, 0));
    isVisit[S] = true;
    bool isAnswer = false;
    int btn = 0;

    while (!intQ.empty())
    {
        int floor, num;
        tie(floor, num) = intQ.front();
        intQ.pop();
        if (floor == G)
        {
            isAnswer = true;
            btn = num;
            break;
        }

        if (floor + U <= F && !isVisit[floor + U])
        {
            isVisit[floor + U] = true;
            intQ.push(make_pair(floor + U, num + 1));
        }

        if (floor - D > 0 && !isVisit[floor - D])
        {
            isVisit[floor - D] = true;
            intQ.push(make_pair(floor - D, num + 1));
        }
    }
    if (isAnswer)
        cout << btn << endl;
    else
        cout << "use the stairs" << endl;

    return 0;
}