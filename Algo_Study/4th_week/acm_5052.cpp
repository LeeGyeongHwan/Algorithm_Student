/* 
ACMICPC
Study Group
4th Week
문제 번호 : 5052
문제 제목 : 전화번호 목록
풀이 날짜 : 2020-08-21
Solved By Reamer 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool compare(string A, string B)
{
    return A.length() < B.length();
}

vector<string> phoneVec;
set<string> strSet;

bool scanPhoneBook()
{
    int size = phoneVec.size();
    for (int i = 0; i < size; i++)
    {
        string st = phoneVec[i];
        int length = st.length();
        for (int j = 1; j <= length; j++)
        {
            string tmp = st.substr(0, j);
            if (strSet.find(tmp) != strSet.end())
                return false;
        }
        strSet.insert(st);
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase, num;

    string phoneNum;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> phoneNum;
            phoneVec.push_back(phoneNum);
        }
        sort(phoneVec.begin(), phoneVec.end(), compare);

        if (scanPhoneBook())
            cout << "YES\n";
        else
            cout << "NO\n";
        strSet.clear();
        phoneVec.clear();
    }
    return 0;
}