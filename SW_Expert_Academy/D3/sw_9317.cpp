/*
난이도 : D3
문제 번호 : 9317
문제 제목 : 석찬이의 받아쓰기
풀이 날짜 : 2020-02-10
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, length;
    string answerStr, cmpStr;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int correct = 0;
        cin >> length;
        cin >> answerStr >> cmpStr;
        for (int j = 0; j < length; j++)
        {
            if (answerStr[j] == cmpStr[j])
                correct++;
        }
        cout << "#" << (i + 1) << " " << correct << "\n";
    }
    return 0;
}