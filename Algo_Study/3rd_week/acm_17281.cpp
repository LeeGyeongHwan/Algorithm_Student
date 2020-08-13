/* 
ACMICPC
Study Group
3rd Week
문제 번호 : 17281
문제 제목 : ⚾
풀이 날짜 : 2020-08-13
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool isDecided[9] = {0};
vector<int> batter[9];
vector<int> battingOrder;
int inning;
int maxScore = 0;

int playGame(vector<int> tmpOrder)
{
    int score = 0;
    int curBatter = 0;
    int base[4] = {0};
    tmpOrder.insert(tmpOrder.begin() + 3, 0); //1번타자 4번타순에 세우기

    for (int i = 0; i < inning; i++)
    {
        int out = 3; //3아웃 초기화
        while (out != 0)
        {
            int battingResult = batter[tmpOrder[curBatter]][i]; //현재 선수의 i번째 이닝 결과
            base[0] = 1;
            switch (battingResult)
            {
            case 1: //안타
                score += base[3];
                for (int i = 3; i >= 1; i--)
                    base[i] = base[i - 1];
                base[0] = 0;
                break;
            case 2: //2루타
                score += base[3] + base[2];
                for (int i = 3; i > 1; i--)
                    base[i] = base[i - 2];
                base[0] = base[1] = 0;
                break;
            case 3: //3루타
                score += base[3] + base[2] + base[1];
                for (int i = 3; i > 2; i--)
                    base[i] = base[i - 3];
                base[0] = base[1] = base[2] = 0;
                break;
            case 4: //홈런
                score += base[3] + base[2] + base[1] + base[0];
                base[0] = base[1] = base[2] = base[3] = 0;
                break;
            default: //아웃
                out--;
                break;
            }
            curBatter = (curBatter + 1) % 9;
        }
        //잔루 지우기
        memset(base, 0, sizeof(base));
    }

    return score;
}

void deploy(int cnt)
{
    if (cnt == 8)
    {
        int score = playGame(battingOrder);
        if (maxScore < score)
            maxScore = score;
        return;
    }

    for (int i = 1; i <= 8; i++)
    {
        if (isDecided[i])
            continue;

        isDecided[i] = true;
        battingOrder.push_back(i);
        deploy(cnt + 1);
        isDecided[i] = false;
        battingOrder.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp;
    cin >> inning;

    for (int i = 0; i < inning; i++) //각 선수별 기록 정보 저장
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> tmp;
            batter[j].push_back(tmp);
        }
    }

    deploy(0);
    cout << maxScore << endl;
    return 0;
}