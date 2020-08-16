/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 9207
문제 제목 : 페그 솔리테어
풀이 날짜 : 2020-08-16
Solved By Reamer 
*/

#include <iostream>
#include <string>
using namespace std;

char peg[5][9];
int minPin = INT32_MAX;
int minMove = INT32_MAX;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void pegSolitaire(int cnt)
{

    bool isValid = false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (peg[i][j] == 'o')
            {
                for (int k = 0; k < 4; k++)
                {
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if (newX >= 0 && newX < 5 && newY >= 0 && newY < 9 && peg[newX][newY] == 'o')
                    {
                        int nextX = newX + dx[k];
                        int nextY = newY + dy[k];
                        if (nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 9 && peg[nextX][nextY] == '.')
                        {
                            isValid = true;
                            peg[i][j] = '.';
                            peg[newX][newY] = '.';
                            peg[nextX][nextY] = 'o';
                            pegSolitaire(cnt + 1);
                            peg[i][j] = 'o';
                            peg[newX][newY] = 'o';
                            peg[nextX][nextY] = '.';
                        }
                    }
                }
            }
        }
    }

    if (!isValid)
    {
        int pin = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (peg[i][j] == 'o')
                    pin++;
            }
        }
        if (pin < minPin)
        {
            minPin = pin;
            minMove = cnt;
        }
        else if (pin == minPin && minMove > cnt)
            minMove = cnt;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase;
    string line;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> line;
            for (int k = 0; k < 9; k++)
                peg[j][k] = line[k];
        }
        pegSolitaire(0);
        cout << minPin << " " << minMove << "\n";
        minPin = INT32_MAX;
        minMove = INT32_MAX;
    }

    return 0;
}