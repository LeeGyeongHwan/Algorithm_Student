/*
난이도 : D3
문제 번호 : 1230
문제 제목 : 암호문3
풀이 날짜 : 2020-02-13
Solved By Reamer
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int length, number, commandNum, start, modeNum;
    char command;
    vector<int> passwordVec, waitVec;
    vector<int>::iterator it;
    for (int i = 0; i < 10; i++)
    {
        cin >> length;
        for (int j = 0; j < length; j++)
        {
            cin >> number;
            passwordVec.push_back(number);
        }
        cin >> commandNum;
        for (int j = 0; j < commandNum; j++)
        {
            cin >> command;
            if (command == 'I')
            {
                cin >> start >> modeNum;
                for (int k = 0; k < modeNum; k++)
                {
                    cin >> number;
                    waitVec.push_back(number);
                }
                it = passwordVec.begin() + start;
                passwordVec.insert(it, waitVec.begin(), waitVec.end());
                waitVec.clear();
            }
            else if (command == 'D')
            {
                cin >> start >> modeNum;
                passwordVec.erase(passwordVec.begin() + start, passwordVec.begin() + start + modeNum);
            }
            else
            {
                cin >> modeNum;
                for (int k = 0; k < modeNum; k++)
                {
                    cin >> number;
                    passwordVec.push_back(number);
                }
            }
        }

        cout << "#" << (i + 1);
        for (int j = 0; j < 10; j++)
            cout << " " << passwordVec[j];
        cout << endl;
        passwordVec.clear();
    }
    return 0;
}