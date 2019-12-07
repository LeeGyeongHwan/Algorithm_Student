#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> aVec, bVec;
    int num;
    int aWin = 0, bWin = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        aVec.push_back(num);
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        bVec.push_back(num);
    }
    for (int i = 0; i < 10; i++)
    {
        if (aVec[i] > bVec[i])
            aWin++;
        else if (aVec[i] < bVec[i])
            bWin++;
    }

    if (aWin == bWin)
        cout << "D" << endl;
    else if (aWin > bWin)
        cout << "A" << endl;
    else
        cout << "B" << endl;

    return 0;
}