/* 
ACMICPC
Study Group
1st Week
문제 번호 : 2251
문제 제목 : 물통 
풀이 날짜 : 2020-07-31
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
using namespace std;

int country[401][401] = {0};
int isVisit[401][401] = {0};
int V, E;
int minDist;
bool isRoute = false;

void calcul(int start, int destination, int distance)
{
    if (distance > minDist)
        return;
    if (start == destination)
    {
        if (distance < minDist)
        {
            minDist = distance;
            isRoute = true;
        }

        return;
    }

    for (int i = 1; i <= V; i++)
    {
        if (start == 0)
        {
            if (country[destination][i] != 0 && !isVisit[destination][i])
            {
                isVisit[destination][i] = true;
                calcul(i, destination, distance + country[destination][i]);
            }
        }
        else
        {
            if (country[start][i] != 0 && !isVisit[start][i])
            {
                isVisit[start][i] = true;
                calcul(i, destination, distance + country[start][i]);
                isVisit[start][i] = false;
            }
        }
    }
}

int main()
{
    int a, b, c;

    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        country[a][b] = c;
    }
    minDist = V * 10000;
    for (int i = 1; i <= V; i++)
    {
        calcul(0, i, 0);
        memset(isVisit, 0, sizeof(isVisit));
    }
    if (isRoute)
        cout << minDist << endl;
    else
        cout << "-1" << endl;
    return 0;
}