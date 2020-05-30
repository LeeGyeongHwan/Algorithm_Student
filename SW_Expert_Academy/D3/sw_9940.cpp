/*
난이도 : D3
문제 번호 : 9940
문제 제목 : 순열1
풀이 날짜 : 2020-05-30
Solved By Reamer
*/

#include <iostream>
#include <string.h>

using namespace std;

int graph[100001] = {0};

int main()
{
    int testCase, num, tmp;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        bool isAnswer = true;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> tmp;
            graph[tmp]++;
            if (graph[tmp] > 1)
                isAnswer = false;
        }

        cout << "#" << i + 1 << " ";
        if (isAnswer)
            cout << "Yes\n";
        else
            cout << "No\n";
        memset(graph, 0, sizeof(graph));
    }

    return 0;
}