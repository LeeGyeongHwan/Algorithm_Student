/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 11559
문제 제목 : Puyo Puyo
풀이 날짜 : 2020-08-09
Solved By Reamer 
*/

#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;

char puyo[12][6];
bool isVisited[12][6];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    queue<pair<int, int>> pairQ, removeQ;
    stack<pair<int, int>> downS;

    string str;
    for (int i = 0; i < 12; i++)
    {
        cin >> str;
        for (int j = 0; j < 6; j++)
        {
            puyo[i][j] = str[j];
        }
    }

    int chain = 0; //연쇄 개수

    while (true)
    {
        int boom = 0;
        // 현재상태에서 터지는 상황 확인
        for (int i = 11; i >= 0; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (puyo[i][j] != '.' && !isVisited[i][j])
                {
                    pairQ.push(make_pair(i, j));
                    isVisited[i][j] = true;
                    char color = puyo[i][j];

                    while (!pairQ.empty()) //BFS탐색하며 인접한 같은 색 확인
                    {
                        int x, y;
                        tie(x, y) = pairQ.front();
                        pairQ.pop();
                        removeQ.push(make_pair(x, y));
                        for (int k = 0; k < 4; k++)
                        {
                            int newX = x + dx[k];
                            int newY = y + dy[k];
                            if (newX >= 0 && newX < 12 && newY >= 0 && newY < 6)
                            {
                                if (!isVisited[newX][newY] && puyo[newX][newY] == color)
                                {
                                    isVisited[newX][newY] = true;
                                    pairQ.push(make_pair(newX, newY));
                                }
                            }
                        }
                    }

                    if (removeQ.size() >= 4) //4개이상이 인접해있으면 폭발
                    {
                        boom++;
                        while (!removeQ.empty())
                        {
                            int x, y;
                            tie(x, y) = removeQ.front();
                            puyo[x][y] = '.';
                            removeQ.pop();
                        }
                    }
                    else
                    {
                        while (!removeQ.empty())
                        {
                            removeQ.pop();
                        }
                    }
                }
            }
        }
        if (boom == 0)
            break;
        //연새 증가
        chain++;
        memset(isVisited, 0, sizeof(isVisited)); //방문 여부 초기화
        
        
        //아래로 내리기
        for (int i = 0; i < 6; i++)
        {
            int firstDot = -1;
            for (int j = 11; j >= 0; j--)
            {
                if (firstDot == -1 && puyo[j][i] == '.')
                    firstDot = j;
                if (firstDot != -1 && puyo[j][i] != '.')
                {
                    downS.push(make_pair(firstDot, j));
                    firstDot = -1;
                }
            }
            while (!downS.empty())
            {
                int x, y;
                tie(x, y) = downS.top();
                downS.pop();
                for (int j = 0; j <= y; j++)
                {
                    puyo[x - j][i] = puyo[y - j][i];
                    puyo[y - j][i] = '.';
                }
            }
        }
    }
    cout << chain << endl;
    return 0;
}