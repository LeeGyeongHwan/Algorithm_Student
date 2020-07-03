/* 
ACMICPC 
문제 번호 : 11943
문제 제목 : 파일 옮기기
풀이 날짜 : 2020-07-03
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int A, B;
    int C, D;

    cin >> A >> B;
    cin >> C >> D;

    int sumA = A + D;
    int sumB = B + C;

    int answer = sumA > sumB ? sumB : sumA;
    cout << answer << endl;

    return 0;
}