/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 15686
문제 제목 : 드래곤 커브
풀이 날짜 : 2020-08-11
Solved By Reamer 
*/

#include <iostream>
#include <vector>
using namespace std;

bool board[101][101] = {0};

void checkVisit(int x, int y)
{
    if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
        board[x][y] = true;
}

int main()
{
    int curve;
    int x, y, d, g;

    vector<pair<int, int>> pairVec;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    cin >> curve;

    for (int i = 0; i < curve; i++)
    {
        bool isMinus = false;
        cin >> x >> y >> d >> g;

        if (d % 2 == 0)
            isMinus = true;

        board[x][y] = true;
        pairVec.push_back(make_pair(dx[d], dy[d]));
        x += dx[d];
        y += dy[d];
        checkVisit(x, y);

        for (int j = 0; j < g; j++)
        {
            int size = pairVec.size();
            //표시
            for (int k = size - 1; k >= 0; k--)
            {
                int tmpDx = pairVec[k].first;
                int tmpDy = pairVec[k].second;

                if (isMinus)
                {
                    pairVec.push_back(make_pair(tmpDy * -1, tmpDx * -1));
                    x += tmpDy * -1;
                    y += tmpDx * -1;
                }
                else
                {
                    pairVec.push_back(make_pair(tmpDy, tmpDx));
                    x += tmpDy;
                    y += tmpDx;
                }

                checkVisit(x, y);
                isMinus = !isMinus;
            }
        }
        pairVec.clear();
    }

    int answer = 0;
    //네꼭지점 확인
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                answer++;
        }
    }

    cout << answer << endl;

    return 0;
}