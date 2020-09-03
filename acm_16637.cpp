/*
ACMICPC
문제 번호 : 16637
문제 제목 : 괄호 추가하기
풀이 날짜 : 2020-09-04
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int N;
int limit;
int maxNum = INT32_MIN;
string str;
bool useBracket[10];
int numArr[10];
vector<char> charVec;

void calculate()
{

    memset(numArr, -1, sizeof(numArr));
    charVec.clear();
    for (int i = 0; i < N; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            numArr[i / 2] = str[i] - '0';
        else
            charVec.push_back(str[i]);
    }

    for (int i = limit - 1; i >= 0; i--)
    {
        if (useBracket[i])
        {
            if (charVec[i] == '+')
            {
                numArr[i] = numArr[i] + numArr[i + 1];
                numArr[i + 1] = -1;
            }
            else if (charVec[i] == '-')
            {
                numArr[i] = numArr[i] - numArr[i + 1];
                numArr[i + 1] = -1;
            }
            else if (charVec[i] == '*')
            {
                numArr[i] = numArr[i] * numArr[i + 1];
                numArr[i + 1] = -1;
            }
        }
    }
    int numIdx = 0;
    int res = numArr[0];
    for (int i = 0; i < limit; i++)
    {
        if (!useBracket[i])
        {
            if (charVec[i] == '+')
                res = res + numArr[i + 1];
            else if (charVec[i] == '-')
                res = res - numArr[i + 1];
            else if (charVec[i] == '*')
                res = res * numArr[i + 1];
        }
    }
    if (maxNum < res)
        maxNum = res;
}

void setBracket(int cnt, int prev)
{
    if (cnt == limit)
    {
        calculate();
        return;
    }

    if (prev == 0)
    {
        useBracket[cnt] = true;
        setBracket(cnt + 1, 1);
    }
    useBracket[cnt] = false;
    setBracket(cnt + 1, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    limit = N / 2;
    cin >> str;

    if (N > 3)
        setBracket(0, 0);
    else
        calculate();

    cout << maxNum << "\n";
    return 0;
}