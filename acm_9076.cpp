/* 
ACMICPC 
문제 번호 : 9076
문제 제목 : 점수 집계 
풀이 날짜 : 2020-06-06
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> intV;
    int test, num;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> num;
            intV.push_back(num);
        }
        sort(intV.begin(), intV.end());
        if (intV[3] - intV[1] >= 4)
            cout << "KIN" << endl;
        else
            cout << intV[1] + intV[2] + intV[3] << endl;
        intV.clear();
    }

    return 0;
}