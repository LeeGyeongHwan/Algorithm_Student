/*
난이도 : D2
문제 번호 : 1970
문제 제목 : 쉬운 거스름돈
풀이 날짜 : 2020-02-12
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, money;
    vector<int> intVec;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int divide = 50000;
        int isFive = true;
        cin >> money;

        while (divide >= 10)
        {
            intVec.push_back(money / divide);

            money = money % divide;
            if (isFive)
            {
                divide /= 5;
                isFive = false;
            }
            else
            {
                divide /= 2;
                isFive = true;
            }
        }

        cout << "#" << (i + 1) << endl;
        for (int j = 0; j < intVec.size(); j++)
        {
            cout << intVec[j] << " ";
        }
        cout << endl;
        intVec.clear();
    }
    return 0;
}
