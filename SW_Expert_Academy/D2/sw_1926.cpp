/*
난이도 : D2
문제 번호 : 1926
문제 제목 : 간단한 369게임
풀이 날짜 : 2020-02-02
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    vector<int> intVec;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        int count369 = 0;
        int tmp = i;
        do
        {
            int div = tmp % 10;
            if (div == 3)
                count369++;
            else if (div == 6)
                count369++;
            else if (div == 9)
                count369++;
            tmp /= 10;
        } while (tmp != 0);

        if (count369 == 0)
            cout << i << " ";
        else
        {
            for (int j = 0; j < count369; j++)
                cout << "-";
            cout << " ";
        }
    }
    return 0;
}