/*
난이도 : D3
문제 번호 : 4698
문제 제목 : 테네스의 특별한 소수
풀이 날짜 : 2020-02-17
Solved By Reamer
*/

#include <iostream>

using namespace std;

const int limit = 1000001;

bool isVisited[limit] = {0};
bool isPrime[limit] = {0};

int main()
{

    int testCase, D, A, B;
    string str;

    cin >> testCase;

    for (int j = 2; j < limit; j++)
    {
        if (!isVisited[j])
        {
            isVisited[j] = true;
            isPrime[j] = true;
            for (int i = j + j; i < limit; i += j)
                isVisited[i] = true;
        }
    }

    for (int i = 0; i < testCase; i++)
    {
        int answer = 0;
        cin >> D >> A >> B;

        for (int j = A; j <= B; j++)
        {
            if (isPrime[j])
            {
                int tmp = j;
                while (tmp != 0)
                {
                    if (tmp % 10 == D)
                    {
                        answer++;
                        break;
                    }
                    tmp /= 10;
                }
            }
        }

        cout << "#" << (i + 1) << " " << answer << endl;
    }
    return 0;
}