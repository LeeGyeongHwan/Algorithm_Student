/* 
ACMICPC 
문제 번호 : 3184
문제 제목 : 양
풀이 날짜 : 2020-05-03
Solved By Reamer 
*/

#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

char graph[250][250];
bool isVisit[250][250] = {0};
int main()
{
    int R, C;
    string str;
    queue<pair<int, int>> pairQ;
    int sheep = 0, wolf = 0;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> str;
        for (int j = 0; j < C; j++)
            graph[i][j] = str[j];
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (graph[i][j] != '#' && !isVisit[i][j])
            {
                int areaSheep = 0, areaWolf = 0;

                pairQ.push(make_pair(i, j));
                isVisit[i][j] = true;

                while (!pairQ.empty())
                {
                    int x, y;
                    tie(x, y) = pairQ.front();
                    pairQ.pop();
                    if (graph[x][y] == 'v')
                        areaWolf++;
                    else if (graph[x][y] == 'o')
                        areaSheep++;

                    if (x - 1 >= 0 && graph[x - 1][y] != '#' && !isVisit[x - 1][y])
                    {
                        isVisit[x - 1][y] = true;
                        pairQ.push(make_pair(x - 1, y));
                    }
                    if (y - 1 >= 0 && graph[x][y - 1] != '#' && !isVisit[x][y - 1])
                    {
                        isVisit[x][y - 1] = true;
                        pairQ.push(make_pair(x, y - 1));
                    }
                    if (x + 1 < R && graph[x + 1][y] != '#' && !isVisit[x + 1][y])
                    {
                        isVisit[x + 1][y] = true;
                        pairQ.push(make_pair(x + 1, y));
                    }
                    if (y + 1 < C && graph[x][y + 1] != '#' && !isVisit[x][y + 1])
                    {
                        isVisit[x][y + 1] = true;
                        pairQ.push(make_pair(x, y + 1));
                    }
                }

                if (areaSheep > areaWolf)
                    sheep += areaSheep;
                else
                    wolf += areaWolf;
            }
        }
    }

    cout << sheep << " " << wolf << endl;
    return 0;
}