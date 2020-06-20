/* 
ACMICPC 
문제 번호 : 9501
문제 제목 : 꿍의 우주여행
풀이 날짜 : 2020-06-20
Solved By Reamer 
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase;
    int spaceship, dist;
    int maxSpeed, fuel, useFuel;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int sumShip = 0;
        cin >> spaceship >> dist;
        for (int j = 0; j < spaceship; j++)
        {
            cin >> maxSpeed >> fuel >> useFuel;
            double maxDist = maxSpeed * fuel / useFuel;
            if (maxDist >= dist)
                sumShip++;
        }
        cout << sumShip << endl;
    }
    return 0;
}