#include <iostream>
#include <vector>
using namespace std;

void printTime(vector<int> tVec)
{
    int h1 = tVec[0], h2 = tVec[3], m1 = tVec[1], m2 = tVec[4], s1 = tVec[2], s2 = tVec[5];
    int h, m, s;
    if (s2 >= s1)
    {
        s = s2 - s1;
    }
    else
    {
        s = s2 + 60 - s1;
        m2--;
    }

    if (m2 >= m1)
    {
        m = m2 - m1;
    }
    else
    {
        m = m2 + 60 - m1;
        h2--;
    }
    h = h2 - h1;
    cout << h << " " << m << " " << s << endl;
}
int main()
{
    vector<int> timeVec;
    int t;

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            cin >> t;
            timeVec.push_back(t);
        }
        printTime(timeVec);
        timeVec.clear();
    }

    return 0;
}