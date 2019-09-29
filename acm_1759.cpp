#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int L, C;

bool check(string str)
{
    int mo = 0, ja = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            mo++;
        else
            ja++;
    }
    return mo >= 1 && ja >= 2;
}

void printEn(int index, int count, vector<char> charVec, string str)
{
    if (count == L)
    {
        if (check(str))
        {
            for (int i = 0; i < str.size(); i++)
            {
                cout << str[i];
            }
            cout << "\n";
        }
        return;
    }
    if (index >= C)
        return;

    printEn(index + 1, count + 1, charVec, str + charVec[index]);
    printEn(index + 1, count, charVec, str);
}

int main()
{
    char tmp;
    vector<char> charVec;

    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> tmp;
        charVec.push_back(tmp);
    }
    sort(charVec.begin(), charVec.end());
    printEn(0, 0, charVec, "");

    return 0;
}