#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numOfPeople;

    vector<vector<int>> intVec;

    cin >> numOfPeople;

    for (int i = 0; i < numOfPeople; i++)
    {
        vector<int> tmpVec;
        int first, second;

        cin >> first >> second;
        tmpVec.push_back(first);
        tmpVec.push_back(second);
        tmpVec.push_back(0);
        intVec.push_back(tmpVec);
        tmpVec.clear();
    }
    for (int j = 0; j < numOfPeople; j++)
    {
        for (int k = j + 1; k < numOfPeople; k++)
        {
            int count = 0;
            if (intVec[j][0] > intVec[k][0])
            {
                count++;
            }
            else if (intVec[j][0] < intVec[k][0])
            {
                count--;
            }
            if (intVec[j][1] > intVec[k][1])
            {
                count++;
            }
            else if (intVec[j][1] < intVec[k][1])
            {
                count--;
            }
            if (count == 2)
                intVec[k][2]++;
            if (count == -2)
                intVec[j][2]++;
        }
    }
    
    for (int i = 0; i < numOfPeople; i++)
    {
        cout<<++intVec[i][2]<<" ";
    }
}