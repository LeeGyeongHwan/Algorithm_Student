/* 
ACMICPC 
문제 번호 : 2754
문제 제목 : 학점계산
풀이 날짜 : 2020-06-23
Solved By Reamer 
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    double grade = 0;
    cin >> str;

    if (str.length() == 2)
    {
        grade = 4 - (str[0] - 'A');
        if (str[1] == '+')
            grade += 0.3;
        else if (str[1] == '-')
            grade -= 0.3;
    }

    cout.precision(1);
    cout << fixed;
    cout << grade << endl;
    return 0;
}