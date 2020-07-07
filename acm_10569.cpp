/* 
ACMICPC 
문제 번호 : 10569
문제 제목 : 다면체 
풀이 날짜 : 2020-07-07
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, V, E;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> V >> E;

        cout << 2 - V + E << endl;
    }

    return 0;
}