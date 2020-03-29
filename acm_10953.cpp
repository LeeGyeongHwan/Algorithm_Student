/*
ACMICPC
문제 번호 : 10953
문제 제목 : A+B - 6
풀이 날짜 : 2020-03-29
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int num, A, B;
    char tmp;
    string numStr;
    

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> numStr;
        stringstream ss;
        ss.str(numStr);
        ss >> A;
        ss >> tmp;
        ss >> B;

        cout << A + B << endl;
    }

    return 0;
}