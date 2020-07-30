/* 
ACMICPC
Study Group
1st Week
문제 번호 : 2251
문제 제목 : 물통 
풀이 날짜 : 2020-07-31
Solved By Reamer 
*/

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int A, B, C;
    bool isVisited[201][201] = {0};
    bool answer[201] = {0};
    queue<tuple<int, int, int>> tupleQ;
    cin >> A >> B >> C;

    tuple<int, int, int> water = make_tuple(0, 0, C);
    tupleQ.push(water);

    while (!tupleQ.empty())
    {

        int a, b, c;
        tie(a, b, c) = tupleQ.front();
        tupleQ.pop();
        // cout << "a : " << a << ", b : " << b << ", c : " << c << endl;

        if (a == 0)
            answer[c] = true;
        if (isVisited[a][b])
            continue;

        isVisited[a][b] = true;
        if (a != 0)
        {
            //A->B
            if (a + b > B)
            {
                tupleQ.push(make_tuple(a + b - B, B, c));
            }
            else
            {
                tupleQ.push(make_tuple(0, a + b, c));
            }
            //A->C
            if (a + c > C)
            {
                tupleQ.push(make_tuple(a + c - C, b, C));
            }
            else
            {
                tupleQ.push(make_tuple(0, b, a + c));
            }
        }

        if (b != 0)
        {
            //B->A
            if (a + b > A)
            {
                tupleQ.push(make_tuple(A, a + b - A, c));
            }
            else
            {
                tupleQ.push(make_tuple(a + b, 0, c));
            }
            //B->C
            if (c + b > C)
            {
                tupleQ.push(make_tuple(a, c + b - C, C));
            }
            else
            {
                tupleQ.push(make_tuple(a, 0, c + b));
            }
        }
        if (c != 0)
        {
            //C->A
            if (a + c > A)
            {
                tupleQ.push(make_tuple(A, b, a + c - A));
            }
            else
            {
                tupleQ.push(make_tuple(a + c, b, 0));
            }
            //C->B
            if (b + c > B)
            {
                tupleQ.push(make_tuple(a, B, b + c - B));
            }
            else
            {
                tupleQ.push(make_tuple(a, b + c, 0));
            }
        }
    }

    for (int i = 0; i <= C; i++)
    {
        if (answer[i])
            cout << i << " ";
    }
    return 0;
}