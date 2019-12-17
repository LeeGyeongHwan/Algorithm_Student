#include <iostream>
#include <vector>

using namespace std;

int gcd(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    else
    {
        return gcd(num2, num1 % num2);
    }
}

int main()
{
    int test, tmp;
    vector<int> intVec;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        cin >> tmp;
        intVec.push_back(tmp);
    }
    int compareNum = intVec.front();

    for (int i = 1; i < test; i++)
    {
        int otherNum = intVec[i];
        int num = gcd(compareNum, otherNum);
        cout << compareNum / num << "/" << otherNum / num << endl;
    }

    return 0;
}