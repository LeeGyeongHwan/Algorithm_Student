/* 
ACMICPC 
문제 번호 : 15734
문제 제목 : 명장 남정훈 
풀이 날짜 : 2020-06-07
Solved By Reamer 
*/

#include <iostream>
using namespace std;

int main()
{
    int L, R, A;
    cin >> L >> R >> A;
    while (A > 0)
    {
        if (L < R)
            L += 1;
        else
            R += 1;
        A--;
    }
    int answer = L > R ? R : L;
    cout << answer * 2 << endl;
}