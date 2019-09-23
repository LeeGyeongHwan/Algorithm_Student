#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int score;
    vector<vector<int>> scoreVec;
    vector<int> tmp;
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> score;
            sum += score;
        }
        tmp.push_back(sum);
        tmp.push_back(i);
        scoreVec.push_back(tmp);
        tmp.clear();
    }
    sort(scoreVec.begin(), scoreVec.end());
    cout << scoreVec.back().at(1) + 1 << " " << scoreVec.back().at(0) << endl;

    return 0;
}