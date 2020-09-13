/*
ACMICPC
문제 번호 : 1292
문제 제목 : 쉽게 푸는 문제
풀이 날짜 : 2020-09-13
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int A, B;
    vector<int> intVec;
    cin >> A >> B;

    int num = 1;
    int cnt = 0;
    for (int i = 0; i < 1000; i++)
    {
        intVec.push_back(num);
        cnt++;
        if (cnt == num)
        {
            cnt = 0;
            num++;
        }
    }
    int sum = 0;
    for (int i = A - 1; i < B; i++)
        sum += intVec[i];
    cout << sum << endl;
    return 0;
}