/*
ACMICPC
문제 번호 : 19689
문제 제목 : 헛간 청약
풀이 날짜 : 2020-09-14
Solved By Reamer
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, W, H, L;
    cin >> N >> W >> H >> L;
    int maxCow = (W / L) * (H / L);

    maxCow = maxCow > N ? N : maxCow;
    cout << maxCow << "\n";

    return 0;
}