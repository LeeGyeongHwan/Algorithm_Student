#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M, tmp;
    vector<pair<int,int> > cost;
    vector<int> eval;
    

    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        cost.push_back(make_pair(tmp,0));
    }
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        eval.push_back(tmp);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (cost[j].first <= eval[i])
            {
                cost[j].second++;
                break;
            }
        }
    }
    int max = 0;
    int index;
    for (int i = 0; i < N; i++)
    {
        if (cost[i].second > max)
        {
            max = cost[i].second;
            index = i;
        }
    }
    cout << index + 1 << endl;
    return 0;
}