/*
난이도 : D3
문제 번호 : 1221
문제 제목 : GNS
풀이 날짜 : 2020-04-05
Solved By Reamer
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int testCase, num;
    string testStr, numStr;
    vector<int> intVec;
    string strArr[] = {"ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN"};

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> testStr >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> numStr;
            if (numStr == "ZRO")
            {
                intVec.push_back(0);
            }
            else if (numStr == "ONE")
            {
                intVec.push_back(1);
            }
            else if (numStr == "TWO")
            {
                intVec.push_back(2);
            }
            else if (numStr == "THR")
            {
                intVec.push_back(3);
            }
            else if (numStr == "FOR")
            {
                intVec.push_back(4);
            }
            else if (numStr == "FIV")
            {
                intVec.push_back(5);
            }
            else if (numStr == "SIX")
            {
                intVec.push_back(6);
            }
            else if (numStr == "SVN")
            {
                intVec.push_back(7);
            }
            else if (numStr == "EGT")
            {
                intVec.push_back(8);
            }
            else if (numStr == "NIN")
            {
                intVec.push_back(9);
            }
        }
        sort(intVec.begin(), intVec.end());
        
        cout<< testStr << endl;
        for(int j=0;j<num;j++)
        {
            cout<<strArr[intVec[j]]<<" ";
        }
        cout<<endl;
        intVec.clear();        
    }
    return 0;
}