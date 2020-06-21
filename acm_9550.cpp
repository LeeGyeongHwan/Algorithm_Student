/* 
ACMICPC 
문제 번호 : 9550
문제 제목 : 아이들은 사탕을 좋아해
풀이 날짜 : 2020-06-21
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase;
    int N, K, tmp;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int candySum = 0;
        cin >> N >> K;

        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            candySum += (tmp / K);
        }
        cout << candySum << endl;
    }
    return 0;
}
