#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tmp;
    vector<int> numVec;
    for (int i = 0; i < 10; i++)
    {
        cin >> tmp;
        int remainder = tmp % 42;
        if (i == 0)
        {
            numVec.push_back(remainder);
            continue;
        }
        int count = 0;
        for (int j = 0; j < numVec.size(); j++)
        {
            if (numVec.at(j) == remainder)
                count++;
        }
        if (count == 0)
            numVec.push_back(remainder);
    }
    cout<<numVec.size()<<endl;

    return 0;
}