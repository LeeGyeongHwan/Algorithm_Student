/*
난이도 : D4
문제 번호 : 3347
문제 제목 : 올림픽 종목 투표
풀이 날짜 : 2020-02-18
Solved By Reamer
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, sport, people, tmp;
    vector<int> sportVec, peopleVec;
    int vote[1000] = {0};

    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int maxVote = 0, popularSport;
        cin >> sport >> people;

        for (int j = 0; j < sport; j++)
        {
            cin >> tmp;
            sportVec.push_back(tmp);
        }
        for (int j = 0; j < people; j++)
        {
            cin >> tmp;
            peopleVec.push_back(tmp);
        }

        for (int j = 0; j < people; j++)
        {
            for (int k = 0; k < sport; k++)
            {
                if (peopleVec[j] >= sportVec[k])
                {
                    vote[k]++;
                    break;
                }
            }
        }

        for (int j = 0; j < sport; j++)
        {
            if (vote[j] > maxVote)
            {
                maxVote = vote[j];
                popularSport = j;
            }
        }
        cout << "#" << (i + 1) << " " << popularSport + 1 << "\n";
        sportVec.clear();
        peopleVec.clear();
        memset(vote, 0, sizeof(vote));
    }

    return 0;
}