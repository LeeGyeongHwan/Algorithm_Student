#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> strvec;
    string tmp;
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> tmp;
        strvec.push_back(tmp);
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = i % 2 == 0 ? 0 : 1; j < 8; j += 2)
        {
            if (strvec[i][j] == 'F')
            {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}