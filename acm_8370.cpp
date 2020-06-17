/* 
ACMICPC 
문제 번호 : 8370
문제 제목 : Plane
풀이 날짜 : 2020-06-17
Solved By Reamer 
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int row1, row2, seat1, seat2;

    cin >> row1 >> seat1 >> row2 >> seat2;

    cout << row1 * seat1 + row2 * seat2 << endl;
    return 0;
}