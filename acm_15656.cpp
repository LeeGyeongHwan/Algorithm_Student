#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intVec;
vector<int> givenVec;

void printNM(int index, int N, int M)
{
    if (index == M)
    {
        for (int i = 0; i < intVec.size(); i++)
        {
            cout << intVec[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++)
    {
        int num = givenVec[i];

        intVec.push_back(num);
        printNM(index + 1, N, M);
        intVec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int N, M, tmp;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        givenVec.push_back(tmp);
    }

    sort(givenVec.begin(), givenVec.end());
    printNM(0, N, M);

    return 0;
}