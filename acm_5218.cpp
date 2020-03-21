/*
ACMICPC
문제 번호 : 5218
문제 제목 : 알파벳 거리
풀이 날짜 : 2020-03-21
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, disNum;
    vector<int> disVec;

    cin >> num;
    string strA, strB;
    for (int i = 0; i < num; i++)
    {
        cin >> strA >> strB;
        for (int j = 0; j < strA.length(); j++)
        {
            if (strB[j] >= strA[j])
                disNum = strB[j] - strA[j];
            else
                disNum = strB[j] - strA[j] + 26;
            disVec.push_back(disNum);
        }

        cout << "Distances:";
        for (int j = 0; j < disVec.size(); j++)
            cout << " " << disVec[j];
        cout << endl;
        disVec.clear();
    }
}