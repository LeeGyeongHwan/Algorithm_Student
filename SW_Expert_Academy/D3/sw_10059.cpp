/*
난이도 : D3
문제 번호 : 10059
문제 제목 : 유효기간 
풀이 날짜 : 2020-07-29
Solved By Reamer
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int testCase;
    string exTime;
    string answer[] = {"MMYY", "YYMM", "AMBIGUOUS", "NA"};
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> exTime;
        int first = stoi(exTime.substr(0, 2));
        int second = stoi(exTime.substr(2, 2));

        int index;
        bool firstValid = false;
        bool secondValid = false;

        if (first > 0 && first <= 12)
            firstValid = true;
        if (second > 0 && second <= 12)
            secondValid = true;

        if (firstValid && secondValid)
            index = 2;
        else if (firstValid && !secondValid)
            index = 0;
        else if (!firstValid && secondValid)
            index = 1;
        else
            index = 3;

        cout << "#" << i + 1 << " " << answer[index] << "\n";
    }

    return 0;
}