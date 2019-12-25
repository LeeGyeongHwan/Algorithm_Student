#include<iostream>

using namespace std;

int main()
{
    int cost,num;
    cin>>cost>>num;

    int mon=1;
    for(int i=0;i<num;i++)
    {
        mon*=10;
    }
    int j=1;
    while(1)
    {
        if(cost<mon*j)
            break;
        j++;
    }
    if((mon*j-cost) > (cost-mon*(j-1)))
    {
        cout<<mon*(j-1)<<endl;
    }
    else
    {
        cout<<mon*j<<endl;
    }
    



    return 0;
}