/* 
ACMICPC
Study Group
1st Week
문제 번호 : 2565
문제 제목 : 전깃줄
풀이 날짜 : 2020-08-04
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x, y;
    vector<pair<int, int>> pole;
    vector<int> intVec;
    vector<int>::iterator it;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        pole.push_back(make_pair(x, y));
    }

    sort(pole.begin(), pole.end());

    for (int i = 0; i < pole.size(); i++)
    {
        int num = pole[i].second;

        it = lower_bound(intVec.begin(), intVec.end(), num);
        if (it == intVec.end())
            intVec.push_back(num);
        else
            *it = num;
    }
    cout << N - intVec.size() << endl;

    return 0;
}