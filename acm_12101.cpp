/*
ACMICPC
문제 번호 : 12101
문제 제목 : 1, 2, 3 더하기 2
풀이 날짜 : 2020-09-15
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
int numArr[10];
vector<string> strVec;

void findCase(int idx, int sum)
{
    if (sum > n)
        return;
    else if (sum == n)
    {
        string tmp = "";
        for (int i = 0; i < idx; i++)
        {
            tmp += to_string(numArr[i]);
        }
        strVec.push_back(tmp);
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        numArr[idx] = i;
        findCase(idx + 1, sum + i);
    }
}

int main()
{

    cin >> n >> k;

    findCase(0, 0);

    if (k > strVec.size())
        cout << "-1\n";
    else
    {
        string answer = strVec[k - 1];
        for (int i = 0; i < answer.length() - 1; i++)
            cout << answer[i] << "+";
        cout << answer.back() << "\n";
    }

    return 0;
}