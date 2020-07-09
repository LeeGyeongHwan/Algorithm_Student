/* 
ACMICPC 
문제 번호 : 10813
문제 제목 : 공 바꾸기
풀이 날짜 : 2020-07-09
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int ball, number, tmp;
    int bucket[101] = {0};
    int A, B;

    cin >> ball >> number;

    for (int i = 1; i <= ball; i++)
    {
        bucket[i] = i;
    }

    for (int i = 0; i < number; i++)
    {
        cin >> A >> B;
        tmp = bucket[A];
        bucket[A] = bucket[B];
        bucket[B] = tmp;
    }

    for (int i = 1; i <= ball; i++)
    {
        cout << bucket[i] << " ";
    }
    return 0;
}