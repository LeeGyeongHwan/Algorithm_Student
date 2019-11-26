#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    vector<string> strVec;
    string tmp;
    string answ = "";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        strVec.push_back(tmp);
    }
    sort(strVec.begin(), strVec.end());
    int count = 1;
    for (int i = 1; i < num; i++)
    {
        if (strVec[i].at(0) == strVec[i - 1].at(0))
        {
            count++;
        }
        else
        {
            if (count >= 5)
                answ += strVec[i - 1].at(0);
            count = 1;
        }
    }
    if (count >= 5)
        answ += strVec.back()[0];
    if (answ != "")
        cout << answ << endl;
    else
        cout << "PREDAJA" << endl;

    return 0;
}