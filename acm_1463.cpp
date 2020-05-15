/* 
ACMICPC 
문제 번호 : 1463
문제 제목 : 1로 만들기
풀이 날짜 : 2020-05-15
*/

#include <iostream>
#include <string.h>
using namespace std;

int numArr[1000001] = {0};

void DP(int num, int count)
{
    if (count > numArr[num])
        return;
    numArr[num] = count;

    if (num == 1)
        return;

    if (num % 3 == 0)
        DP(num / 3, count + 1);
    if (num % 2 == 0)
        DP(num / 2, count + 1);

    DP(num - 1, count + 1);
}

int main()
{
    int num;
    cin >> num;

    memset(numArr, INT8_MAX, sizeof(numArr));
    DP(num, 0);

    cout << numArr[1] << endl;
    return 0;
}