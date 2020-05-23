/* 
ACMICPC 
문제 번호 : 17173
문제 제목 : 배수들의 합
풀이 날짜 : 2020-05-23
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    int tmp;
    int sum = 0;
    vector<int> intVec;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    for (int i = 1; i <= N; i++)
    {
        bool isExist = false;
        for (int j = 0; j < intVec.size(); j++)
        {
            if (i % intVec[j] == 0)
            {
                isExist = true;
                break;
            }
        }
        if (isExist)
            sum += i;
    }

    cout << sum << endl;

    return 0;
}