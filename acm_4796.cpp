/* 
ACMICPC 
문제 번호 : 4796
문제 제목 : 캠핑
풀이 날짜 : 2020-06-04
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int L, P, V;
    int caseNum = 1;
    while (1)
    {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;

        int answer = V / P * L;
        if (V % P <= L)
            answer += V % P;
        else
            answer += L;

        cout << "Case " << caseNum << ": " << answer << endl;
        ;
        caseNum++;
    }

    return 0;
}