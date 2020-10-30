/* 
ACMICPC 
문제 번호 : 13241 
문제 제목 : 최소공배수
풀이 날짜 : 2020-10-31
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int gcd(int A, int B)
{
    if (B == 0)
        return A;
    return gcd(B, A % B);
}

int main()
{
    long long A, B;
    cin >> A >> B;
    int gcdNum = gcd(A, B);

    cout << A * B / gcdNum << endl;

    return 0;
}