/* 
ACMICPC 
문제 번호 : 4635
문제 제목 : Speed Limit
풀이 날짜 : 2020-07-25
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int num;
    int speed, elapsedTime;

    while (1)
    {
        int previousTime = 0;
        int miles = 0;
        cin >> num;
        if (num == -1)
            break;

        for (int i = 0; i < num; i++)
        {
            cin >> speed >> elapsedTime;
            miles += speed * (elapsedTime - previousTime);
            previousTime = elapsedTime;
        }

        cout << miles << " miles" << endl;
    }

    return 0;
}