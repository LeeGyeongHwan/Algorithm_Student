#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int numofSet, tmp;
    vector<int> lottoVec;
    vector<int> selectVec;

    cin >> numofSet;
    do
    {
        for (int i = 0; i < numofSet; i++)
        {
            cin >> tmp;
            lottoVec.push_back(tmp);
            if (i < 6)
            {
                selectVec.push_back(1);
            }
            else
            {
                selectVec.push_back(2);
            }
        }
        do
        {
            for (int i = 0; i < numofSet; i++)
            {
                if (selectVec[i] == 1)
                {
                    cout << lottoVec[i] << " ";
                }
            }
            cout << "\n";
        } while (next_permutation(selectVec.begin(), selectVec.end()));
        cout<<endl;
        cin >> numofSet;
        lottoVec.clear();
        selectVec.clear();
    } while (numofSet != 0);

    return 0;
}