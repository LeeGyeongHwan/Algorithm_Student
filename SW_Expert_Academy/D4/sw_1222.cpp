/*
난이도 : D4
문제 번호 : 1222
문제 제목 : 계산기1
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int length;
    string expression;
    for (int i = 0; i < 10; i++)
    {
        int answer = 0;
        string tmp = "";
        cin >> length;
        cin >> expression;

        for (int j = 0; j < length; j++)
        {
            if (expression[j] >= 48 && expression[j] <= 57)
                answer += (int)(expression[j] - 48);
        }
        cout << "#" << (i + 1) << " " << answer << endl;
    }
    return 0;
}
