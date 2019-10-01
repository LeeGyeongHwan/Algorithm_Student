#include <iostream>
#include <vector>
using namespace std;

bool check[10];
vector<int> intVec;

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

    for (int i = 1; i <= N; i++)
    {
        if (intVec.size() > 0 && i < intVec.back())
            continue;
        if (check[i])
            continue;
        check[i] = true;
        intVec.push_back(i);
        printNM(index + 1, N, M);
        intVec.pop_back();
        check[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    printNM(0, N, M);

    return 0;
}