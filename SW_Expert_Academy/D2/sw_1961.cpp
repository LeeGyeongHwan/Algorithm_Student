/*
난이도 : D2
문제 번호 : 1961
문제 제목 : 숫자 배열 회전
풀이 날짜 : 2020-02-16
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int testCase, N, tmp;
    vector<vector<int>> intVV;
    vector<int> tmpVec;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> tmp;
                tmpVec.push_back(tmp);
            }
            intVV.push_back(tmpVec);
            tmpVec.clear();
        }
        cout << "#" << (i + 1) << endl;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cout << intVV[N - k - 1][j];
            }
            cout << " ";
            for (int k = 0; k < N; k++)
            {
                cout << intVV[N - j - 1][N - k - 1];
            }
            cout << " ";
            for (int k = 0; k < N; k++)
            {
                cout << intVV[k][N - j - 1];
            }
            cout << "\n";
        }
        intVV.clear();
    }
    return 0;
}
