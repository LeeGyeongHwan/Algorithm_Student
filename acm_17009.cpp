/* 
ACMICPC 
문제 번호 : 17009
문제 제목 : Winning Score
풀이 날짜 : 2020-06-08
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int A1, A2, A3, B1, B2, B3;

    cin >> A3 >> A2 >> A1;
    cin >> B3 >> B2 >> B1;

    int scoreA = A3 * 3 + A2 * 2 + A1 * 1;
    int scoreB = B3 * 3 + B2 * 2 + B1 * 1;

    if (scoreA > scoreB)
        cout << "A" << endl;
    else if (scoreA == scoreB)
        cout << "T" << endl;
    else
        cout << "B" << endl;

    return 0;
}