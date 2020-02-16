/*
난이도 : D3
문제 번호 : 5431
문제 제목 : 민석이의 과제 체크하기
풀이 날짜 : 2020-02-16
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int testCase, people, submit, tmp;

    int student[101] = {0};

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> people >> submit;
        for (int j = 0; j < submit; j++)
        {
            cin >> tmp;
            student[tmp] = 1;
        }
        cout << "#" << (i + 1);
        for (int j = 1; j <= people; j++)
        {
            if (student[j] == 0)
                cout << " " << j;
        }
        cout << endl;
        memset(student, 0, sizeof(student));
    }
    return 0;
}