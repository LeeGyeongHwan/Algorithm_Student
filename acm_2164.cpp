#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    queue<int> intQ;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        intQ.push(i);
    }
    while (intQ.size() != 1)
    {
        intQ.pop();
        intQ.push(intQ.front());
        intQ.pop();
    }
    cout << intQ.front() << endl;

    return 0;
}