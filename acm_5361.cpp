/* 
ACMICPC 
문제 번호 : 5361
문제 제목 : 전투 드로이드 가격
풀이 날짜 : 2020-06-19
Solved By Reamer 
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testCase;
    int A, B, C, D, E;
    double sensor[] = {350.34, 230.90, 190.55, 125.30, 180.90};
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> A >> B >> C >> D >> E;
        double sensorSum = sensor[0] * A + sensor[1] * B + sensor[2] * C + sensor[3] * D + sensor[4] * E;
        cout << fixed;
        cout.precision(2);
        cout << "$" << sensorSum << endl;
    }
    return 0;
}