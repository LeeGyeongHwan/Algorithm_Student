/*
난이도 : D2
문제 번호 : 1984
문제 제목 : 중간 평균값 구하기
풀이 날짜 : 2020-02-05
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int testCase, tmp;
    vector<int> intVec;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        sort(intVec.begin(), intVec.end());
        int sumNum = 0;
        
        for (int j = 1; j < 9; j++)
            sumNum += intVec[j];

        float avg = (float)sumNum / 8;
        cout << "#" << (i + 1) << " " << round(avg) << endl;
        intVec.clear();
    }

    return 0;
}