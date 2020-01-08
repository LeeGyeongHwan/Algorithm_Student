#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    char tmp;
    bool visited[1001][1001]={false};

    vector< vector<int> > mazeVec;
    vector<int> tmpVec;
    queue<pair<int,int> > pairQ;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>tmp;
            int num=tmp-48;
            tmpVec.push_back(num);
        }
        mazeVec.push_back(tmpVec);
        tmpVec.clear();
    }
    
    pairQ.push(make_pair(0,0));
    visited[0][0]=true;

    while(!pairQ.empty())
    {
        int pointX=pairQ.front().first;
        int pointY=pairQ.front().second;
        pairQ.pop();
        
        if((pointX-1)>=0)
        {
            if(visited[pointX-1][pointY]==false && mazeVec[pointX-1][pointY]!=0)
            {
                visited[pointX-1][pointY]=true;
                pairQ.push(make_pair(pointX-1,pointY));
                mazeVec[pointX-1][pointY]=mazeVec[pointX][pointY]+1;
            }
        }
        if((pointY+1)<M)
        {
            if(visited[pointX][pointY+1]==false && mazeVec[pointX][pointY+1]!=0)
            {
                visited[pointX][pointY+1]=true;
                pairQ.push(make_pair(pointX,pointY+1));
                mazeVec[pointX][pointY+1]=mazeVec[pointX][pointY]+1;
            }
        }
        if((pointX+1)<N)
        {
            if(visited[pointX+1][pointY]==false && mazeVec[pointX+1][pointY]!=0)
            {
                visited[pointX+1][pointY]=true;
                pairQ.push(make_pair(pointX+1,pointY));
                mazeVec[pointX+1][pointY]=mazeVec[pointX][pointY]+1;
            }
        }
        if((pointY-1)>=0)
        {
            if(visited[pointX][pointY-1]==false && mazeVec[pointX][pointY-1]!=0)
            {
                visited[pointX][pointY-1]=true;
                pairQ.push(make_pair(pointX,pointY-1));
                mazeVec[pointX][pointY-1]=mazeVec[pointX][pointY]+1;
            }
        }

    }

    cout<<mazeVec[N-1][M-1]<<endl;

    return 0;
}