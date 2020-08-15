/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 15683
문제 제목 : 감시
풀이 날짜 : 2020-08-15
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int office[8][8] = {0};
int tmpOffice[8][8] = {0};
vector<pair<pair<int, int>, int>> cctv;
vector<int> direction;
int N, M;
int minBlindSpot = 64;

int findBlindSpot()
{
    for (int i = 0; i < N; i++) //tmpOffice에 값 복사
    {
        for (int j = 0; j < M; j++)
            tmpOffice[i][j] = office[i][j];
    }

    for (int i = 0; i < direction.size(); i++) //감시 영역 찾기
    {
        int x = cctv[i].first.first;
        int y = cctv[i].first.second;
        int type = cctv[i].second;

        int dir = direction[i];
        int newX, newY;
        //위 방향
        if (dir == 0 || (type == 3 && dir == 3) || (type == 4 && (dir == 1 || dir == 3)))
        {
            newX = x + dx[0];
            newY = y + dy[0];
            while (true)
            {
                if (newX >= 0 && newX < N && newY >= 0 && newY < M && tmpOffice[newX][newY] != 6)
                {
                    tmpOffice[newX][newY] = 7; //감시영역으로 표시
                    newX += dx[0];
                    newY += dy[0];
                }
                else
                    break;
            }
        }
        //오른쪽방향
        if (type == 5 || (type == 1 && dir == 1) || (type == 2 && dir == 1) || (type == 3 && (dir == 0 || dir == 1)) || (type == 4 && (dir == 0 || dir == 1 || dir == 2)))
        {
            newX = x + dx[1];
            newY = y + dy[1];
            while (true)
            {
                if (newX >= 0 && newX < N && newY >= 0 && newY < M && tmpOffice[newX][newY] != 6)
                {
                    tmpOffice[newX][newY] = 7; //감시영역으로 표시
                    newX += dx[1];
                    newY += dy[1];
                }
                else
                    break;
            }
        }
        //아래방향
        if (type == 5 || (type == 1 && dir == 2) || (type == 2 && dir == 0) || (type == 3 && (dir == 1 || dir == 2)) || (type == 4 && (dir == 3 || dir == 1 || dir == 2)))
        {
            newX = x + dx[2];
            newY = y + dy[2];
            while (true)
            {
                if (newX >= 0 && newX < N && newY >= 0 && newY < M && tmpOffice[newX][newY] != 6)
                {
                    tmpOffice[newX][newY] = 7; //감시영역으로 표시
                    newX += dx[2];
                    newY += dy[2];
                }
                else
                    break;
            }
        }
        //왼쪽방향
        if (type == 5 || (type == 1 && dir == 3) || (type == 2 && dir == 1) || (type == 3 && (dir == 2 || dir == 3)) || (type == 4 && (dir == 0 || dir == 3 || dir == 2)))
        {
            newX = x + dx[3];
            newY = y + dy[3];
            while (true)
            {
                if (newX >= 0 && newX < N && newY >= 0 && newY < M && tmpOffice[newX][newY] != 6)
                {
                    tmpOffice[newX][newY] = 7; //감시영역으로 표시
                    newX += dx[3];
                    newY += dy[3];
                }
                else
                    break;
            }
        }
    }

    int blindSpot = 0;
    for (int i = 0; i < N; i++) //사각지대 개수 찾기
    {
        for (int j = 0; j < M; j++)
        {
            if (tmpOffice[i][j] == 0)
                blindSpot++;
        }
    }
    return blindSpot;
}

void combination(int idx)
{
    if (idx == cctv.size())
    {
        int blindSpot = findBlindSpot();
        if (blindSpot < minBlindSpot)
            minBlindSpot = blindSpot;
        return;
    }

    int typeOfCCTV = cctv[idx].second;
    if (typeOfCCTV == 2) //종류에 따른 cctv 방향 경우의 수 생성
    {
        for (int i = 0; i < 2; i++)
        {
            direction.push_back(i);
            combination(idx + 1);
            direction.pop_back();
        }
    }
    else if (typeOfCCTV == 5)
    {
        direction.push_back(0);
        combination(idx + 1);
        direction.pop_back();
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            direction.push_back(i);
            combination(idx + 1);
            direction.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp;
            cin >> tmp; //0 - 빈칸, 1~5 - CCTV, 6 - 벽
            office[i][j] = tmp;
            if (tmp >= 1 && tmp <= 5)
                cctv.push_back({{i, j}, tmp});
        }
    }

    combination(0);
    cout << minBlindSpot << "\n";
    return 0;
}