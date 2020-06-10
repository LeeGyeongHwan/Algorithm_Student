/* 
ACMICPC 
문제 번호 : 13221
문제 제목 : Manhattan 
풀이 날짜 : 2020-06-10
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int x, y, n;
    int tmpX, tmpY;
    int minDistance = 201;
    int distance;
    int minX, minY;
    cin >> x >> y;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmpX >> tmpY;
        distance = abs(tmpX - x) + abs(tmpY - y);
        if (distance < minDistance)
        {
            minDistance = distance;
            minX = tmpX;
            minY = tmpY;
        }
    }
    cout << minX << " " << minY << endl;

    return 0;
}