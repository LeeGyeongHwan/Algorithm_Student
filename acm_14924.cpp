/* 
ACMICPC 
문제 번호 : 14924
문제 제목 : 폰 노이만과 파리
풀이 날짜 : 2020-06-30
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int S, T, D;

    cin >> S >> T >> D;
    int time = D / (2 * S);

    cout << time * T << endl;

    return 0;
}