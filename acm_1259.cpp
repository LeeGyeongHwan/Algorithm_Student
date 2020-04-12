/* 
ACMICPC 
문제 번호 : 1259 
문제 제목 : 팰린드롬수
풀이 날짜 : 2020-04-12
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int num;
    vector<int> intVec;
    while (1)
    {
        bool isPalin = true;
        cin >> num;
        if (num == 0)
            break;

        while (num != 0)
        {
            int tmp = num % 10;
            intVec.push_back(tmp);
            num /= 10;
        }
        for (int i = 0; i < intVec.size() / 2; i++)
        {
            if (intVec[i] != intVec[intVec.size() - i - 1])
            {
                isPalin = false;
                break;
            }
        }
        if (isPalin)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        intVec.clear();
    }

    return 0;
}