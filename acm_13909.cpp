/* 
ACMICPC 
문제 번호 : 13909
문제 제목 : 창문 닫기
풀이 날짜 : 2020-05-24
*/

#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
    int num;
    cin >> num;

    for (int i = 1;; i++)
    {
        if (i * i <= num)
            answer++;
        else
            break;
    }
    cout << answer << endl;

    return 0;
}