#include <iostream>
#include <vector>
using namespace std;

bool c[10];
int a[10];
void printNM(int index, int N, int M)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (c[i])
            continue;
        c[i] = true;
        a[index] = i;
        printNM(index + 1, N, M);
        c[i] = false;
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