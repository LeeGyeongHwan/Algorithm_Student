/*
난이도 : D3
문제 번호 : 1220
문제 제목 : Magnetic
풀이 날짜 : 2020-03-23
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int side, tmp;
    vector<vector<int>> intVec;
    vector<int> tmpVec;

    for (int i = 0; i < 10; i++)
    {
        int count = 0;

        cin >> side;
        for (int j = 0; j < side; j++)
        {
            for (int k = 0; k < side; k++)
            {
                cin >> tmp;
                tmpVec.push_back(tmp);
            }
            intVec.push_back(tmpVec);
            tmpVec.clear();
        }

        for (int j = 0; j < side; j++)
        {
            bool isPair = false;
            for (int k = 0; k < side; k++)
            {
                if (intVec[k].at(j) == 1)
                    isPair = true;
                else if (intVec[k].at(j) == 2 && isPair)
                {
                    isPair = false;
                    count++;
                }
            }
        }

        cout << "#" << (i + 1) << " " << count << "\n";
        intVec.clear();
    }
    return 0;
}