#include <iostream>
#include <vector>
using namespace std;

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
        
        intVec.push_back(i);
        printNM(index + 1, N, M);
        intVec.pop_back();
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