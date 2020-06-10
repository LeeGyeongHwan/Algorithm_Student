/* 
ACMICPC 
문제 번호 : 5717
문제 제목 : 상근이의 친구들
풀이 날짜 : 2020-06-11
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int M, F;

    while (1)
    {
        cin >> M >> F;

        if (M == 0 && F == 0)
            break;

        cout << M + F << endl;
    }
    return 0;
}