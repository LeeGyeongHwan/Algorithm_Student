#include <iostream>

using namespace std;

int main()
{
    int N, tmp;
    int sumRefused = 0;
    cin >> N;
    bool visited[101] = {false};
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (visited[tmp] == false)
            visited[tmp] = true;
        else
            sumRefused++;
    }
    cout << sumRefused << endl;
    return 0;
}