/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 15686
문제 제목 : 치킨 배달
풀이 날짜 : 2020-08-07
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int shopNum;
int N, M;
bool isVisited[13];
vector<pair<int, int>> houseVec, chickenVec;
int minDistance = INT32_MAX;

void combination(int count, int idx)
{
    if (count == M)
    {
        int chickDistance = 0;
        for (int i = 0; i < houseVec.size(); i++)
        {
            int tmpDistance = 100;
            for (int j = 0; j < shopNum; j++)
            {
                if (isVisited[j])
                {
                    int tmp = abs(chickenVec[j].first - houseVec[i].first) + abs(chickenVec[j].second - houseVec[i].second);
                    if (tmp < tmpDistance)
                        tmpDistance = tmp;
                }
            }
            chickDistance += tmpDistance;
        }
        if (chickDistance < minDistance)
            minDistance = chickDistance;
        return;
    }

    if (idx > shopNum)
        return;
    if (idx < shopNum)
    {
        isVisited[idx] = true;
        combination(count + 1, idx + 1);
        isVisited[idx] = false;
        combination(count, idx + 1);
    }
}

int main()
{
    int tmp;
    int city[50][50];

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            city[i][j] = tmp;
            if (tmp == 1)
                houseVec.push_back(make_pair(i, j));
            else if (tmp == 2)
                chickenVec.push_back(make_pair(i, j));
        }
    }

    shopNum = chickenVec.size();
    combination(0, 0);
    cout << minDistance << endl;

    return 0;
}