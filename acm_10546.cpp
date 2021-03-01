/*
ACMICPC
문제 번호 : 10546
문제 제목 : 배부른 마라토너
풀이 날짜 : 2021-03-01
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    string name;
    vector<string> participants, completes;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> name;
        participants.push_back(name);
    }

    for (int i = 0; i < N - 1; i++)
    {
        cin >> name;
        completes.push_back(name);
    }
    sort(participants.begin(), participants.end());
    sort(completes.begin(), completes.end());

    bool isLast = true;

    for (int i = 0; i < N - 1; i++)
    {
        if (participants[i].compare(completes[i]))
        {
            cout << participants[i] << endl;
            isLast = false;
            break;
        }
    }

    if (isLast)
        cout << participants[N - 1] << endl;

    return 0;
}