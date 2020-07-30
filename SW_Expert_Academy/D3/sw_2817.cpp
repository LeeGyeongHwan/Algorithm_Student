/*
난이도 : D3
문제 번호 : 2817
문제 제목 : 부분 수열의 합
풀이 날짜 : 2020-07-30
Solved By Reamer
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool isSelected[20] = {0};
vector<int> intVec;
int N, K;
int cnt;

void reFunc(int index, int sum)
{
    if (index == N)
    {
        if (sum == K)
            cnt++;
        return;
    }
    else
    {
        isSelected[index] = true;
        reFunc(index + 1, sum + intVec[index]);
        isSelected[index] = false;
        reFunc(index + 1, sum);
    }
}

int main()
{
    int T, tmp;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cnt = 0;
        cin >> N >> K;

        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            intVec.push_back(tmp);
        }

        reFunc(0, 0);

        intVec.clear();
        memset(isSelected, 0, sizeof(isSelected));
        cout << "#" << i + 1 << " " << cnt << "\n";
    }
    return 0;
}
