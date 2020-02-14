/*
난이도 : D3
문제 번호 : 7853
문제 제목 : 오타 
풀이 날짜 : 2020-02-14
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    vector<int> intVec;
    string str;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        long long word = 1;
        cin >> str;

        if (str.length() != 1)
        {
            for (int j = 0; j < str.length(); j++)
            {
                if (j == 0)
                {
                    if (str[j] != str[j + 1])
                        intVec.push_back(2);
                    else
                        intVec.push_back(1);
                }
                else if (j == str.length() - 1)
                {
                    if (str[j] != str[j - 1])
                        intVec.push_back(2);
                    else
                        intVec.push_back(1);
                }
                else
                {
                    if (str[j] != str[j - 1] && str[j] != str[j + 1] && str[j - 1] != str[j + 1])
                        intVec.push_back(3);
                    else if (str[j] == str[j - 1] && str[j] == str[j + 1] && str[j - 1] == str[j + 1])
                        intVec.push_back(1);
                    else
                        intVec.push_back(2);
                }
            }
        }
        for (int j = 0; j < intVec.size(); j++)
        {
            word *= intVec[j];
            word %= 1000000007;
        }

        cout << "#" << (i + 1) << " " << word << endl;
        intVec.clear();
    }
    return 0;
}