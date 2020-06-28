/* 
ACMICPC 
문제 번호 : 17496
문제 제목 : 스타후르츠
풀이 날짜 : 2020-06-28
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int day, starFruit, num, price;
    cin >> day >> starFruit >> num >> price;

    cout << (day - 1) / starFruit * num * price << endl;
    return 0;
}