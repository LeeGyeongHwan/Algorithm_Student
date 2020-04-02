/*
ACMICPC
문제 번호 : 13235
문제 제목 : 팰린드롬
풀이 날짜 : 2020-04-02
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    for(int i=0;i<str.length()/2;i++)
    {
        if(str[i]!=str[str.length()-i-1])
        {
            cout<<"false"<<endl;
            return 0;
        }
    }
    cout<<"true"<<endl;
    return 0;
}