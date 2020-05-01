/* 
ACMICPC 
문제 번호 : 13458 
문제 제목 : 시험 감독
풀이 날짜 : 2020-05-01
Solved By Reamer 
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int test, people, supervisor, subSupervisor;
    long long supervisorSum = 0;
    vector<int> peopleVec;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cin >> people;
        peopleVec.push_back(people);
    }
    cin >> supervisor >> subSupervisor;

    for (int i = 0; i < test; i++)
    {
        int tmp = peopleVec[i];
        tmp -= supervisor;
        supervisorSum += 1;
        if (tmp > 0)
        {
            int isAdd = tmp % subSupervisor ? 1 : 0;
            supervisorSum += tmp / subSupervisor + isAdd;
        }
    }
    cout << supervisorSum << endl;

    return 0;
}