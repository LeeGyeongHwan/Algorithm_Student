/*
ACMICPC
문제 번호 : 11722
문제 제목 : 가장 긴 감소하는 부분 수열
풀이 날짜 : 2020-08-16
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, tmp;
    vector<int> intVec;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (intVec.empty())
            intVec.push_back(tmp);
        else
        {
            if (intVec.back() > tmp)
                intVec.push_back(tmp);
            else
            {
                for (int j = 0; j < intVec.size(); j++)
                {
                    if (intVec[j] <= tmp)
                    {
                        intVec[j] = tmp;
                        break;
                    }
                }
            }
        }
    }
    cout << intVec.size() << endl;
    return 0;
}