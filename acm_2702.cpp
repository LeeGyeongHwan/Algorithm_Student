/* 
ACMICPC 
문제 번호 : 2702
문제 제목 : 초6 수학
풀이 날짜 : 2020-06-25
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int GCD(int x, int y)
{
    if (y == 0)
        return x;
    else
        return GCD(y, x % y);
}

int main()
{
    int testCase;
    int A, B;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> A >> B;
        int gcd = GCD(A, B);
        cout << A * B / gcd << " " << gcd << endl;
    }

    return 0;
}
