/* 
ACMICPC 
문제 번호 : 17174
문제 제목 : 전체 계산 횟수
풀이 날짜 : 2020-06-22
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int count = 0;
    cin >> N >> M;

    count += N;

    while (N / M > 0)
    {
        count += N / M;
        N /= M;
    }

    cout << count << endl;
    return 0;
}