/* 
ACMICPC 
문제 번호 : 10709
문제 제목 : 기상캐스터
풀이 날짜 : 2020-11-09
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int W, H;
    char tmp;

    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        int cnt = -1;
        for (int j = 0; j < W; j++)
        {
            cin >> tmp;
            if (tmp == 'c')
            {
                cout << "0 ";
                cnt = 1;
            }
            else
            {
                cout << cnt << " ";
                if (cnt != -1)
                    cnt++;
            }
        }
        cout << "\n";
    }
    return 0;
}