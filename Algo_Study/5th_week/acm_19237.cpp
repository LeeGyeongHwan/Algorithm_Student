/* 
ACMICPC
Study Group
5th Week
문제 번호 : 19237
문제 제목 : 어른 상어
풀이 날짜 : 2020-08-30
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <tuple>

using namespace std;
int N, M, K;
int sea[20][20];
int smell[20][20];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<tuple<int, int, int>> shark;
vector<int> sharkDir, deadShark;
vector<vector<int>> priorityVec[400];

bool noSmell[4];
bool mySmell[4];

int moveShark()
{
    int time = 0;
    while (true)
    {
        deadShark.clear();
        //0번 상어부터 이동시킴

        int aliveShark = shark.size();
        for (int i = 0; i < aliveShark; i++)
        {
            memset(noSmell, 0, sizeof(noSmell));
            memset(mySmell, 0, sizeof(mySmell));
            int sharkNum, x, y;
            tie(sharkNum, x, y) = shark[i];
            //상어위치에서 주변 냄새가 있는지 확인
            int notSmellCnt = 0;
            int mySmellCnt = 0;
            for (int j = 0; j < 4; j++)
            {
                int newX = x + dx[j];
                int newY = y + dy[j];
                if (newX >= 0 && newX < N && newY >= 0 && newY < N)
                {
                    if (smell[newX][newY] / 400 == 0)
                    {
                        noSmell[j] = true;
                        notSmellCnt++;
                    }
                    else if (smell[newX][newY] % 400 == sharkNum)
                    {
                        //내 냄새가 여러개일경우에도 우선순위를따라야됨!!************************
                        mySmell[j] = true;
                    }
                }
            }
            if (notSmellCnt != 0) //있으면 우선순위에 따라
            {
                int curDir = sharkDir[sharkNum];
                for (int j = 0; j < 4; j++)
                {
                    int priorityDir = priorityVec[sharkNum][curDir][j] - 1;
                    if (noSmell[priorityDir])
                    {
                        sharkDir[sharkNum] = priorityDir;
                        break;
                    }
                }
            }
            else //없으면 자신의 냄새가 있는칸
            {
                int curDir = sharkDir[sharkNum];
                for (int j = 0; j < 4; j++)
                {
                    int priorityDir = priorityVec[sharkNum][curDir][j] - 1;
                    if (mySmell[priorityDir])
                    {
                        sharkDir[sharkNum] = priorityDir;
                        break;
                    }
                }
            }
        } //방향을 정하기만 해야됨

        //냄새 흐려지게함 -400;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (smell[i][j] >= 400)
                    smell[i][j] -= 400;
            }
        }

        //dir에 따른 이동

        for (int i = 0; i < aliveShark; i++)
        {
            int sharkNum, x, y;
            tie(sharkNum, x, y) = shark[i];
            int newX = x + dx[sharkDir[sharkNum]];
            int newY = y + dy[sharkDir[sharkNum]];
            sea[x][y] = 0;
            if (sea[newX][newY] != 0)
            {
                deadShark.push_back(i);
                continue;
            }
            smell[newX][newY] = 400 * K + sharkNum;
            sea[newX][newY] = sharkNum + 1;
            shark[i] = {sharkNum, newX, newY};
        }
        time++;
        if (time > 1000)
            return -1;
        //남아있는 상어를 확인해서
        if (!deadShark.empty())
        {
            for (int i = deadShark.size() - 1; i >= 0; i--)
            {
                shark.erase(shark.begin() + deadShark[i]);
            }
        }

        if (shark.size() == 1)
            break;
        //0번만 남으면 끝
    }
    return time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;
    vector<int> tmpVec;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            sea[i][j] = tmp;
            if (tmp != 0)
            {
                shark.push_back({tmp - 1, i, j});
                smell[i][j] = 400 * K + tmp - 1; //0번 400, 1번 401 ...
            }
        }
    }
    sort(shark.begin(), shark.end());
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        sharkDir.push_back(tmp - 1);
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cin >> tmp;
                tmpVec.push_back(tmp);
            }
            priorityVec[i].push_back(tmpVec);
            tmpVec.clear();
        }
    }

    int time = moveShark();

    cout << time << "\n";

    return 0;
}