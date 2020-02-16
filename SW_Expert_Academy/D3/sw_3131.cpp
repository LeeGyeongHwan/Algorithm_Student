/*
난이도 : D3
문제 번호 : 3131
문제 제목 : 100만 이하의 모든 소수
풀이 날짜 : 2020-02-16
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int limit = 1000001;
    bool isVisited[limit] = {0};
    vector<int> intVec;

    for (int i = 2; i < limit; i++)
    {
        if (isVisited[i] == false)
        {
            intVec.push_back(i);
            for (int j = i; j < limit; j += i)
                isVisited[j] = true;
        }
    }

    for(int i=0;i<intVec.size();i++)
        cout<<intVec[i]<<" ";
    return 0;
}