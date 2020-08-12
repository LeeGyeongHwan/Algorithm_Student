/*
ACMICPC
문제 번호 : 2210
문제 제목 : 숫자판 점프
풀이 날짜 : 2020-08-12
Solved By Reamer
*/

#include <iostream>
#include <set>

using namespace std;

set<int> intSet;
int map[5][5];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void findNum(int x, int y, int num, int length)
{
    if (length == 6)
    {
        intSet.insert(num);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5)
        {
            findNum(newX, newY, num * 10 + map[newX][newY], length + 1);
        }
    }
}

int main()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            findNum(i, j, map[i][j], 1);
        }
    }
    cout << intSet.size() << endl;
    return 0;
}