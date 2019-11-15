#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Test, num;
    vector<int> abilVec;

    cin >> Test;

    for (int i = 0; i < Test; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> num;
            abilVec.push_back(num);
        }
        int hp = abilVec[0] + abilVec[4];
        int mp = abilVec[1] + abilVec[5];
        int attac = abilVec[2] + abilVec[6];
        int defen = abilVec[3] + abilVec[7];
        hp = hp < 1 ? 1 : hp;
        mp = mp < 1 ? 1 : mp;
        attac = attac < 0 ? 0 : attac;
        int abil = hp + mp * 5 + 2 * attac + 2 * defen;
        cout << abil << endl;
        abilVec.clear();
    }

    return 0;
}