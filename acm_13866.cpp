/* 
ACMICPC 
문제 번호 : 13866
문제 제목 : 팀 나누기
풀이 날짜 : 2020-06-29
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int tmp, teamA, teamB;
    vector<int> intVec;

    for (int i = 0; i < 4; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end());

    teamA = intVec[0] + intVec[3];
    teamB = intVec[1] + intVec[2];

    cout << abs(teamA - teamB) << endl;
    return 0;
}