/*
ACMICPC
문제 번호 : 10995
문제 제목 : 별 찍기 - 20
풀이 날짜 : 2020-04-19
Solved By Reamer
*/

#include <iostream>
using namespace std;

int main()
{
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        
        for(int j=0;j<num;j++)
        {
            if(i%2==0)
                cout<<"* ";
            else
                cout<<" *";
        }   
        
        
        cout << endl;
    }

    return 0;
}