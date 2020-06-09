/* 
ACMICPC 
문제 번호 : 5523
문제 제목 : 경기 결과
풀이 날짜 : 2020-06-09
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int N, A, B;
    int winA = 0, winB = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        if (A > B)
            winA++;
        else if (A < B)
            winB++;
    }
    cout << winA << " " << winB << endl;

    return 0;
}