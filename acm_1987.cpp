/* 
ACMICPC 
문제 번호 : 1987
문제 제목 : 알파벳
풀이 날짜 : 2020-05-11
Solved By Reamer 
*/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int R, C;
char graph[20][20];
int maxLenght = 0;
int wayX[] = {0, 1, 0, -1};
int wayY[] = {1, 0, -1, 0};
bool isVisit[20][20] = {0};
int charArr[26] = {0};

void DFS(int x, int y, int length)
{

    isVisit[x][y] = true;
    char tmp = graph[x][y];
    charArr[tmp - 'A']++;
    if (charArr[tmp - 'A'] >= 2)
    {
        if (maxLenght < length - 1)
            maxLenght = length - 1;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int tmpX = x + wayX[i];
        int tmpY = y + wayY[i];
        char tmpChar = graph[tmpX][tmpY];
        if (!(tmpX >= 0 && tmpX < R && tmpY >= 0 && tmpY < C) || isVisit[tmpX][tmpY])
            continue;

        DFS(tmpX, tmpY, length + 1);
        charArr[tmpChar - 'A']--;
        isVisit[tmpX][tmpY] = false;
    }
}

int main()
{
    string str;

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> str;
        for (int j = 0; j < C; j++)
        {
            graph[i][j] = str[j];
        }
    }
    DFS(0, 0, 1);
    if (maxLenght)
        cout << maxLenght << endl;
    else
        cout << R * C << endl;

    return 0;
}