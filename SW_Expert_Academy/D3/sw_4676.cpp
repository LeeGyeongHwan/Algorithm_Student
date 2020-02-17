/*
난이도 : D3
문제 번호 : 4676
문제 제목 : 늘어지는 소리 만들기
풀이 날짜 : 2020-02-17
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int testCase, hyphen, tmp;
    vector<int> intVec;
    string str;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        string answer = "";
        int start = 0;
        cin >> str;
        cin >> hyphen;
        for (int j = 0; j < hyphen; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        sort(intVec.begin(), intVec.end());

        for (int j = 0; j < intVec.size(); j++)
        {
            if (intVec[j] > start)
            {
                int tmp = start;
                for (int k = tmp; k < intVec[j]; k++)
                {
                    answer += str[k];
                    start++;
                }
            }
            answer += "-";
        }
        for (int j = start; j < str.size(); j++)
            answer += str[j];
        cout << "#" << (i + 1) << " " << answer << endl;
        intVec.clear();
    }
    return 0;
}