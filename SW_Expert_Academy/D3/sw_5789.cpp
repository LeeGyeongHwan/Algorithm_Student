/*
난이도 : D3
문제 번호 : 5789
문제 제목 : 현주의 상자 바꾸기
풀이 날짜 : 2020-02-21
Solved By Reamer
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int boxArr[1001] = {0};

    int testCase, box, num, start, end;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> box >> num;

        for (int j = 0; j < num; j++)
        {
            cin >> start >> end;
            for (int k = start-1; k < end; k++)
                boxArr[k] = (j + 1);
        }
        cout << "#" << (i + 1);
        for (int j = 0; j < box; j++)
            cout << " " << boxArr[j];
        cout << "\n";
        memset(boxArr, 0, sizeof(boxArr));
    }

    return 0;
}