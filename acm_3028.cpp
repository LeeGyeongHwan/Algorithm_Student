/* 
ACMICPC 
문제 번호 : 3028
문제 제목 : 창영마을 
풀이 날짜 : 2020-06-16
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    string str;
    int tmp;
    int ball[] = {1, 0, 0};

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == 'A')
        {
            tmp = ball[0];
            ball[0] = ball[1];
            ball[1] = tmp;
        }
        else if (str[i] == 'B')
        {
            tmp = ball[1];
            ball[1] = ball[2];
            ball[2] = tmp;
        }
        else
        {
            tmp = ball[0];
            ball[0] = ball[2];
            ball[2] = tmp;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (ball[i] == 1)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}