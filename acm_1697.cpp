#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N, K, num;
    bool check[100001];
    int dist[100001];
    queue<int> intQueue;

    cin >> N >> K;

    intQueue.push(N);
    dist[N] = 0;
    check[N] = true;
    while (!intQueue.empty())
    {
        num = intQueue.front();
        intQueue.pop();
        if (num == K)
            break;

        if (!check[num - 1] && num - 1 >= 0)
        {
            check[num - 1] = true;
            intQueue.push(num - 1);
            dist[num - 1] = dist[num] + 1;
        }
        if (!check[num + 1] && num + 1 < 100001)
        {
            check[num + 1] = true;
            intQueue.push(num + 1);
            dist[num + 1] = dist[num] + 1;
        }
        if (!check[2 * num] && num * 2 < 100001)
        {
            check[num + num] = true;
            intQueue.push(num + num);
            dist[num + num] = dist[num] + 1;
        }
    }
    cout << dist[K] << endl;

    return 0;
}