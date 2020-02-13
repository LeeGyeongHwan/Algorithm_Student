/*
난이도 : D2
문제 번호 : 1940
문제 제목 : 가랏! RC카!
풀이 날짜 : 2020-02-13
Solved By Reamer
*/

#include <iostream>

using namespace std;

int main()
{
    int testCase, command, mode, speed;

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        cin >> command;
        int distance = 0;
        int currentSpeed = 0;
        for (int j = 0; j < command; j++)
        {
            cin >> mode;
            if (mode != 0)
            {
                cin >> speed;
                if (mode == 1)
                    currentSpeed += speed;
                else
                {
                    currentSpeed = currentSpeed - speed < 0 ? 0 : currentSpeed - speed;
                }
            }
            distance += currentSpeed;
        }
        cout << "#" << (i + 1) << " " << distance << endl;
    }
    return 0;
}