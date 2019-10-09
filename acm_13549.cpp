#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main()
{
    int N, K;
    bool visit[100001];
    int distance[100001];
    deque<int> deVec;

    cin >> N >> K;

    deVec.push_front(N);
    visit[N] = true;
    distance[N] = 0;

    while (!deVec.empty())
    {
        int num = deVec.front();
        //cout << num << ", deque size: " << deVec.size() << endl;
        deVec.pop_front();
        if (num == K)
        {
            // cout << "break" << endl;
            break;
        }

        if (!visit[2 * num] && (num * 2 < 100001))
        {
            // cout << "*2" << endl;
            deVec.push_front(2 * num);
            visit[2 * num] = true;
            distance[num * 2] = distance[num];
        }
        if (!visit[num - 1] && (num - 1 >= 0))
        {
            // cout << "-1" << endl;
            deVec.push_back(num - 1);
            visit[num - 1] = true;
            distance[num - 1] = distance[num] + 1;
        }
        if (!visit[num + 1] && (num + 1 < 100001))
        {
            // cout << "+1" << endl;
            deVec.push_back(num + 1);
            visit[num + 1] = true;
            distance[num + 1] = distance[num] + 1;
        }
    }

    cout << distance[K] << endl;

    return 0;
}