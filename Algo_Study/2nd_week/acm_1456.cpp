/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 1456
문제 제목 : 거의 소수
풀이 날짜 : 2020-08-12
Solved By Reamer 
*/

#include <iostream>

using namespace std;

bool isVisited[10000001] = {0};
int main()
{
    long long A, B;
    long long tmp;
    cin >> A >> B;
    int count = 0;
    for (int i = 2; i < 10000001; i++)
    {
        if (!isVisited[i])
        {
            tmp = (long long)i * (long long)i;
            while (tmp <= B)
            {
                if (tmp >= A)
                    count++;

                if (100000000000000 / i >= tmp)
                    tmp *= (long long)i;
                else
                    break;
            }

            for (int j = i + i; j < 10000001; j += i)
            {
                isVisited[j] = true;
            }
        }
    }
    cout << count << endl;
    return 0;
}