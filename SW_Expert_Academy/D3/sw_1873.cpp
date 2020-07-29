/*
난이도 : D3
문제 번호 : 1873
문제 제목 : 상호의 배틀필드
풀이 날짜 : 2020-07-29
Solved By Reamer
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T, H, W, N;
    string str, command;
    char map[21][21];
    pair<int, int> startP;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int way;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> H >> W;

        for (int j = 0; j < H; j++)
        {
            cin >> str;
            for (int k = 0; k < W; k++)
            {
                map[j][k] = str[k];

                if (str[k] == '^')
                {
                    startP = make_pair(j, k);
                    way = 0;
                }
                else if (str[k] == '>')
                {
                    startP = make_pair(j, k);
                    way = 1;
                }
                else if (str[k] == 'v')
                {
                    startP = make_pair(j, k);
                    way = 2;
                }
                else if (str[k] == '<')
                {
                    startP = make_pair(j, k);
                    way = 3;
                }
            }
        }

        cin >> N;
        cin >> command;

        for (int j = 0; j < N; j++)
        {
            if (command[j] == 'S')
            {
                int bulletX = startP.first;
                int bulletY = startP.second;
                while (true)
                {
                    bulletX = bulletX + dx[way];
                    bulletY = bulletY + dy[way];
                    if (bulletX < 0 || bulletX >= H || bulletY < 0 || bulletY >= W)
                        break;

                    if (map[bulletX][bulletY] == '*')
                    {
                        map[bulletX][bulletY] = '.';
                        break;
                    }
                    else if (map[bulletX][bulletY] == '#')
                        break;
                }
            }
            else
            {
                char direction;
                if (command[j] == 'U')
                {
                    way = 0;
                    direction = '^';
                }
                else if (command[j] == 'D')
                {
                    way = 2;
                    direction = 'v';
                }
                else if (command[j] == 'L')
                {
                    way = 3;
                    direction = '<';
                }
                else if (command[j] == 'R')
                {
                    way = 1;
                    direction = '>';
                }

                int newX, newY;
                newX = startP.first + dx[way];
                newY = startP.second + dy[way];
                if (newX < 0 || newX >= H || newY < 0 || newY >= W)
                {
                    map[startP.first][startP.second] = direction;
                    continue;
                }

                if (map[newX][newY] == '.')
                {
                    map[startP.first][startP.second] = '.';
                    startP = make_pair(newX, newY);
                }
                map[startP.first][startP.second] = direction;
            }
        }

        cout << "#" << i + 1 << " ";
        for (int j = 0; j < H; j++)
        {
            for (int k = 0; k < W; k++)
                cout << map[j][k];
            cout << endl;
        }
    }

    return 0;
}