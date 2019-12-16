#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numOfnum[10] = {0};
    int num;

    cin >> num;

    while (1)
    {
        if (num / 10 == 0)
        {
            if (num == 9)
                numOfnum[6]++;
            else
                numOfnum[num]++;
            break;
        }
        int tmp = num % 10;
        if (tmp == 9)
            numOfnum[6]++;
        else
            numOfnum[tmp]++;
        num /= 10;
    }
    numOfnum[6] = (numOfnum[6] + 1) / 2;
    int maxSet = 0;
    for (int i = 0; i < 10; i++)
    {
        if (maxSet < numOfnum[i])
            maxSet = numOfnum[i];
    }
    cout << maxSet << endl;
}