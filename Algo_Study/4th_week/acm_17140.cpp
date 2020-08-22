/* 
ACMICPC
Study Group
4th Week
문제 번호 : 17140
문제 제목 : 이차원 배열과 연산
풀이 날짜 : 2020-08-23
Solved By Reamer 
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
#include <vector>

using namespace std;

int arr[101][101] = {0};
int rowLength[101] = {0};
int colLength[101] = {0};
set<int> intSet;
vector<pair<int, int>> pairVec;
bool compare(pair<int, int> A, pair<int, int> B)
{
    if (A.second == B.second)
        return A.first < B.first;
    return A.second < B.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, k, tmp;
    int row = 3;
    int col = 3;
    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> arr[i][j];
        }
        rowLength[i] = 3;
        colLength[i] = 3;
    }
    int time = 0;
    while (true)
    {
        if (time > 100 || arr[r][c] == k)
            break;
        if (row >= col) //R연산
        {
            memset(colLength, 0, sizeof(colLength));
            for (int i = 1; i <= row; i++)
            {
                for (int j = 1; j <= col; j++)
                {

                    tmp = arr[i][j];
                    if (tmp == 0)
                        continue;

                    if (intSet.find(tmp) == intSet.end())
                    {
                        intSet.insert(tmp);
                        pairVec.push_back({tmp, 1});
                    }
                    else
                    {
                        for (int k = 0; k < pairVec.size(); k++)
                        {
                            if (pairVec[k].first == tmp)
                            {
                                pairVec[k].second++;
                                break;
                            }
                        }
                    }
                }
                sort(pairVec.begin(), pairVec.end(), compare);
                int size = pairVec.size();
                if (size > 50)
                    size = 50;
                for (int j = 0; j < size; j++)
                {
                    arr[i][(j + 1) * 2 - 1] = pairVec[j].first;
                    arr[i][(j + 1) * 2] = pairVec[j].second;
                    colLength[(j + 1) * 2 - 1]++;
                    colLength[(j + 1) * 2]++;
                }
                rowLength[i] = size * 2;

                pairVec.clear();
                intSet.clear();
            }
            int maxCol = 0;
            for (int i = 1; i <= row; i++)
            {
                if (rowLength[i] > maxCol)
                    maxCol = rowLength[i];
            }
            col = maxCol;
            for (int i = 1; i <= row; i++)
            {
                for (int j = rowLength[i] + 1; j <= col; j++)
                    arr[i][j] = 0;
            }
        }
        else //C연산
        {
            memset(rowLength, 0, sizeof(rowLength));
            for (int i = 1; i <= col; i++)
            {
                for (int j = 1; j <= row; j++)
                {

                    tmp = arr[j][i];
                    if (tmp == 0)
                        continue;

                    if (intSet.find(tmp) == intSet.end())
                    {
                        intSet.insert(tmp);
                        pairVec.push_back({tmp, 1});
                    }
                    else
                    {
                        for (int k = 0; k < pairVec.size(); k++)
                        {
                            if (pairVec[k].first == tmp)
                            {
                                pairVec[k].second++;
                                break;
                            }
                        }
                    }
                }
                sort(pairVec.begin(), pairVec.end(), compare);
                int size = pairVec.size();
                if (size > 50)
                    size = 50;

                for (int j = 0; j < size; j++)
                {
                    arr[(j + 1) * 2 - 1][i] = pairVec[j].first;
                    arr[(j + 1) * 2][i] = pairVec[j].second;
                    rowLength[(j + 1) * 2 - 1]++;
                    rowLength[(j + 1) * 2]++;
                }
                colLength[i] = size * 2;

                pairVec.clear();
                intSet.clear();
            }
            int maxRow = 0;
            for (int i = 1; i <= col; i++)
            {
                if (colLength[i] > maxRow)
                    maxRow = colLength[i];
            }
            row = maxRow;
            for (int i = 1; i <= col; i++)
            {
                for (int j = colLength[i] + 1; j <= row; j++)
                    arr[j][i] = 0;
            }
        }
        time++;
    }
    if (time > 100)
        cout << "-1\n";
    else
        cout << time << "\n";
    return 0;
}