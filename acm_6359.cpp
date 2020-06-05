/* 
ACMICPC 
문제 번호 : 6359
문제 제목 : 만취한 상범
풀이 날짜 : 2020-06-05
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, num;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> num;
        int answer;
        for (int j = 1;; j++)
        {
            if (num < j * j)
            {
                answer = j - 1;
                break;
            }
        }
        cout << answer << endl;
    }

    return 0;
}