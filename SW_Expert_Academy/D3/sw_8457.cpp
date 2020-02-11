/*
난이도 : D3
문제 번호 : 8457
문제 제목 : 알 덴테 스파게티
풀이 날짜 : 2020-02-11
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, N, B, E, tmp;
    vector<int> intVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int sandglass = 0;
        cin >> N >> B >> E;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        for (int j = 0; j < N; j++)
        {
            int num = intVec[j];
            while (num <= B + E)
            {
                if (num >= B - E)
                {
                    sandglass++;
                    break;
                }
                num += intVec[j];
            }
        }

        cout << "#" << (i + 1) << " " << sandglass << endl;
        intVec.clear();
    }
    return 0;
}