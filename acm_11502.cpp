/*
ACMICPC
문제 번호 : 11502
문제 제목 : 세 개의 소수 문제
풀이 날짜 : 2020-08-26
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> primeVec;
bool isSelected[1001];
bool isChecked[1001];
vector<int> answer;

bool isAnswer = false;

void findCase(int cnt, int idx, int num)
{
    if (cnt == 3)
    {
        int sum = 0;
        for (int i = 0; i < answer.size(); i++)
            sum += answer[i];
        if (sum == num)
            isAnswer = true;

        return;
    }

    for (int i = idx; i < primeVec.size(); i++)
    {
        if (primeVec[i] > num)
            break;

        isChecked[i] = true;
        answer.push_back(primeVec[i]);
        findCase(cnt + 1, idx, num);
        if (isAnswer)
            break;
        answer.pop_back();
        isChecked[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase, num;
    cin >> testCase;

    for (int i = 2; i <= 1000; i++)
    {
        if (!isSelected[i])
        {
            primeVec.push_back(i);
            for (int j = i * i; j <= 1000; j += i)
                isSelected[j] = true;
        }
    }

    for (int i = 0; i < testCase; i++)
    {
        cin >> num;
        findCase(0, 0, num);
        if (isAnswer)
        {
            for (int i = 0; i < answer.size(); i++)
                cout << answer[i] << " ";
            cout << "\n";
        }
        else
            cout << "0\n";

        answer.clear();
        memset(isChecked, 0, sizeof(isChecked));
        isAnswer = false;
    }

    return 0;
}