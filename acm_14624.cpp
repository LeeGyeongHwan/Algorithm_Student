/* 
ACMICPC 
문제 번호 : 14624
문제 제목 : 전북대학교 
풀이 날짜 : 2020-05-22
*/

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N % 2 == 0)
        cout << "I LOVE CBNU" << endl;
    else
    {
        for (int i = 0; i < N; i++)
            cout << "*";
        cout << endl;
        for (int i = 0; i < N / 2 + 1; i++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                if (N / 2 - j == i)
                    cout << "*";
                else
                    cout << " ";
            }
            for (int j = 0; j <= N; j++)
            {
                if (j == i)
                {
                    cout << "*";
                    break;
                }                    
                else
                    cout << " ";
            }

            cout << endl;
        }
    }

    return 0;
}