/* 
ACMICPC
Study Group
4th Week
문제 번호 : 1043
문제 제목 : 거짓말
풀이 날짜 : 2020-08-26
Solved By Reamer 
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> partyPeople[50];
bool truthParty[50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int people, party;
    int wise, person, num;
    set<int> wisePeople;

    cin >> people >> party;

    cin >> wise;
    for (int i = 0; i < wise; i++)
    {
        cin >> person;
        wisePeople.insert(person);
    }

    for (int i = 0; i < party; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> person;
            partyPeople[i].push_back(person);
        }
    }

    while (true)
    {
        bool isChange = false;

        for (int i = 0; i < party; i++)
        {
            if (truthParty[i])
                continue;
            bool isExist = false;
            for (int j = 0; j < partyPeople[i].size(); j++)
            {
                person = partyPeople[i][j];
                if (wisePeople.find(person) != wisePeople.end())
                {
                    isExist = true;
                    break;
                }
            }
            if (isExist)
            {
                for (int j = 0; j < partyPeople[i].size(); j++)
                {
                    wisePeople.insert(partyPeople[i][j]);
                }
                truthParty[i] = true;
                isChange = true;
            }
        }
        if (!isChange)
            break;
    }
    int totalParty = 0;
    for (int i = 0; i < party; i++)
    {
        if (truthParty[i] == 0)
            totalParty++;
    }
    cout << totalParty << "\n";

    return 0;
}