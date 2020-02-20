/*
난이도 : D3
문제 번호 : 6900
문제 제목 : 주혁이의 복권 당첨
풀이 날짜 : 2020-02-20
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, winNum, myNum, price, tmp;
    string tmpStr;
    vector<string> winVec, myVec;
    vector<int> priceVec;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int totalMoney = 0;
        cin >> winNum >> myNum;
        for (int j = 0; j < winNum; j++)
        {
            cin >> tmpStr >> price;
            winVec.push_back(tmpStr);
            priceVec.push_back(price);
        }
        for (int j = 0; j < myNum; j++)
        {
            cin >> tmpStr;
            myVec.push_back(tmpStr);
        }

        for (int j = 0; j < myNum; j++)
        {
            for (int k = 0; k < winNum; k++)
            {
                bool isCorrect = true;
                for (int l = 0; l < 8; l++)
                {
                    if (!(winVec[k].at(l) == '*' || winVec[k].at(l) == myVec[j].at(l)))
                    {
                        isCorrect = false;
                        break;
                    }
                }
                if (isCorrect)
                {
                    totalMoney += priceVec[k];
                    break;
                }
            }
        }
        cout << "#" << (i + 1) << " " << totalMoney << "\n";
        priceVec.clear();
        winVec.clear();
        myVec.clear();
    }

    return 0;
}