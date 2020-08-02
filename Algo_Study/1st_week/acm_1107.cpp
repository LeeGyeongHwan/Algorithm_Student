/* 
ACMICPC
Study Group
1st Week
문제 번호 : 1107
문제 제목 : 리모컨
풀이 날짜 : 2020-08-02
Solved By Reamer 
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool button[10];
vector<int> intVec;
int channel;
int nearChannel = INT32_MAX;

void recur(int cnt, int degree)
{
    if (cnt == degree)
    {
        int num = 0;
        for (int i = 0; i < intVec.size(); i++)
        {
            num = num * 10 + intVec[i];
        }
        if (abs(nearChannel - channel) >= abs(num - channel))
            nearChannel = num;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (button[i])
        {
            intVec.push_back(i);
            recur(cnt + 1, degree);
            intVec.pop_back();
        }
    }
}

int main()
{

    int broken, btn;
    int current = 100;
    memset(button, 1, sizeof(button));

    cin >> channel;
    cin >> broken;

    for (int i = 0; i < broken; i++)
    {
        cin >> btn;
        button[btn] = false;
    }

    int degree = 1;
    int tmp = channel / 10;
    while (tmp != 0)
    {
        degree++;
        tmp /= 10;
    }

    recur(0, degree + 1);
    recur(0, degree);

    if (degree > 1)
        recur(0, degree - 1);
    //비교
    if (nearChannel == INT32_MAX)
    {
        cout << abs(channel - current) << endl;
    }
    else
    {
        int remote = nearChannel / 10;
        int sizeRemote = 1;
        while (remote != 0)
        {
            sizeRemote++;
            remote /= 10;
        }

        int upDown = abs(channel - current);
        int remoteBtn = abs(nearChannel - channel) + sizeRemote;

        int minNum = upDown > remoteBtn ? remoteBtn : upDown;
        cout << minNum << endl;
    }

    return 0;
}