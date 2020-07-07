/* 
ACMICPC 
문제 번호 : 4592
문제 제목 : 중복을 없애자
풀이 날짜 : 2020-07-08
Solved By Reamer 
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num, tmp;
    vector<int> intVec;

    while (1)
    {
        cin >> num;

        if (num == 0)
            break;

        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        cout << intVec.front() << " ";

        for (int i = 1; i < intVec.size(); i++)
        {
            if (intVec[i - 1] != intVec[i])
                cout << intVec[i] << " ";
        }

        cout << "$\n";
        intVec.clear();
    }

    return 0;
}