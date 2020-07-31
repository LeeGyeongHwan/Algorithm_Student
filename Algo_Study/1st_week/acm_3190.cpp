/* 
ACMICPC
Study Group
1st Week
문제 번호 : 3190
문제 제목 : 뱀 
풀이 날짜 : 2020-07-31
Solved By Reamer 
*/

#include <iostream>
#include <deque>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    int N, K, L, X;
    int x, y;
    char C;
    int map[101][101] = {0};
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector<pair<int, char>> pairVec;
    deque<pair<int, int>> pairDeq;

    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> x >> y;
        map[x][y] = 2;
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> X >> C;
        pairVec.push_back(make_pair(X, C));
    }

    pairDeq.push_back(make_pair(1, 1));
    map[1][1] = 1;
    int timer = 0;
    int change = 0;
    int direction = 1;

    while (!pairDeq.empty())
    {
        timer++;
        int tmpX, tmpY;
        tie(tmpX, tmpY) = pairDeq.front();
        // cout << "x : " << tmpX << ", y : " << tmpY << endl;

        tmpX += dx[direction];
        tmpY += dy[direction];
        if (!(tmpX >= 1 && tmpX <= N && tmpY >= 1 && tmpY <= N))
            break;
        if (map[tmpX][tmpY] == 1)
            break;

        if (map[tmpX][tmpY] == 0)
        {
            int deleteX, deleteY;
            tie(deleteX, deleteY) = pairDeq.back();
            map[deleteX][deleteY] = 0;
            pairDeq.pop_back();
        }

        map[tmpX][tmpY] = 1;
        pairDeq.push_front(make_pair(tmpX, tmpY));

        //
        if (timer == pairVec[change].first)
        {
            if (pairVec[change].second == 'L')
            {
                direction--;
                if (direction < 0)
                    direction = 3;
            }
            else
            {
                direction++;
                direction %= 4;
            }
            change++;
        }
    }
    cout << timer << endl;
    return 0;
}