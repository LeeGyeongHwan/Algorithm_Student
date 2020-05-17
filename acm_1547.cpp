/* 
ACMICPC 
문제 번호 : 1547
문제 제목 : 공
풀이 날짜 : 2020-05-17
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int N, X, Y;
    map<int, int> M;
    M[1] = 1;
    M[2] = 0;
    M[3] = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> X >> Y;

        int tmp = M.find(X)->second;

        M[X] = M.find(Y)->second;
        M[Y] = tmp;
    }

    for (auto it = M.begin(); it != M.end(); it++)
    {
        if (it->second == 1)
            cout << it->first << endl;
    }
    return 0;
}