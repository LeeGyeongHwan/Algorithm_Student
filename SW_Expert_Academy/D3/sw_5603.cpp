/*
난이도 : D3
문제 번호 : 5603
문제 제목 : 건초더미
풀이 날짜 : 2020-03-12
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testCase, num, tmp;
    vector<int> intVec;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int avg = 0, total = 0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> tmp;
            avg += tmp;
            intVec.push_back(tmp);
        }
        avg = avg / num;

        for (int j = 0; j < num; j++)
        {
            if (intVec[j] > avg)
                total += (intVec[j] - avg);
        }
        cout << "#" << (i + 1) << " " << total << endl;
        intVec.clear();
    }
    return 0;
}