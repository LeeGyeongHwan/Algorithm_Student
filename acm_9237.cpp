/* 
ACMICPC 
문제 번호 : 9237
문제 제목 : 이장님 초대
풀이 날짜 : 2020-11-24
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int N, tmp;
    vector<int> intVec;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    sort(intVec.begin(), intVec.end(), compare);

    int maxDay = 0;
    for (int i = 0; i < N; i++)
        maxDay = max(maxDay, intVec[i] + (i + 1));

    cout << maxDay + 1 << endl;
    return 0;
}