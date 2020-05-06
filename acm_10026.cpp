/*
ACMICPC
문제 번호 : 10026
문제 제목 : 적록색약 
풀이 날짜 : 2020-05-06
Solved By Reamer
*/

#include<iostream>
#include<queue>
#include<tuple>
#include<string.h>
using namespace std;

int main()
{
    char graph[100][100];
    bool isVisit[100][100]={0};
    int N;
    int color = 0,colorWeak = 0;
    queue<pair<int,int>> pairQ;
    string str;

    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>str;
        for(int j=0;j<N;j++)
        {
            graph[i][j]=str[j];
        }
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!isVisit[i][j])
            {
                color++;
                pairQ.push(make_pair(i,j));
                isVisit[i][j]=true;

                while(!pairQ.empty())
                {
                    int x,y;
                    tie(x,y) = pairQ.front();
                    pairQ.pop();

                    if(x-1>=0 && !isVisit[x-1][y] && graph[x][y]==graph[x-1][y])
                    {
                        pairQ.push(make_pair(x-1,y));
                        isVisit[x-1][y]=true;
                    }
                    if(y-1>=0 && !isVisit[x][y-1] && graph[x][y]==graph[x][y-1])
                    {
                        pairQ.push(make_pair(x,y-1));
                        isVisit[x][y-1]=true;
                    }
                    if(x+1<N && !isVisit[x+1][y] && graph[x][y]==graph[x+1][y])
                    {
                        pairQ.push(make_pair(x+1,y));
                        isVisit[x+1][y]=true;
                    }
                    if(y+1<N && !isVisit[x][y+1] && graph[x][y]==graph[x][y+1])
                    {
                        pairQ.push(make_pair(x,y+1));
                        isVisit[x][y+1]=true;
                    }
                    if(graph[x][y]=='R')
                        graph[x][y]='G';
                }
            }

        }
    }
    memset(isVisit,0,sizeof(isVisit));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!isVisit[i][j])
            {
                colorWeak++;
                pairQ.push(make_pair(i,j));
                isVisit[i][j]=true;

                while(!pairQ.empty())
                {
                    int x,y;
                    tie(x,y) = pairQ.front();
                    pairQ.pop();

                    if(x-1>=0 && !isVisit[x-1][y] && graph[x][y]==graph[x-1][y])
                    {
                        pairQ.push(make_pair(x-1,y));
                        isVisit[x-1][y]=true;
                    }
                    if(y-1>=0 && !isVisit[x][y-1] && graph[x][y]==graph[x][y-1])
                    {
                        pairQ.push(make_pair(x,y-1));
                        isVisit[x][y-1]=true;
                    }
                    if(x+1<N && !isVisit[x+1][y] && graph[x][y]==graph[x+1][y])
                    {
                        pairQ.push(make_pair(x+1,y));
                        isVisit[x+1][y]=true;
                    }
                    if(y+1<N && !isVisit[x][y+1] && graph[x][y]==graph[x][y+1])
                    {
                        pairQ.push(make_pair(x,y+1));
                        isVisit[x][y+1]=true;
                    }
                }
            }

        }
    }
    cout<<color<<" "<<colorWeak<<endl;
    return 0;
}