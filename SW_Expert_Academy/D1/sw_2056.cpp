/*
난이도 : D1
문제 번호 : 2056
문제 제목 : 연월일 달력
풀이 날짜 : 2020-02-03
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, month, day;
    string ymd, year;

    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        bool isvalid = true;
        string answer = "";
        cin >> ymd;
        year = ymd.substr(0, 4);
        month = stoi(ymd.substr(4, 2));
        day = stoi(ymd.substr(6, 2));

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (!(day >= 1 && day <= 31))
                isvalid = false;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (!(day >= 1 && day <= 30))
                isvalid = false;
        }
        else if (month == 2)
        {
            if (!(day >= 1 && day <= 28))
                isvalid = false;
        }
        else
            isvalid = false;

        if (!isvalid)
            answer = "-1";
        else
        {
            answer += year + "/" + ymd.substr(4, 2) + "/" + ymd.substr(6, 2);
        }

        cout << "#" << (i + 1) << " " << answer << endl;
    }
    return 0;
}