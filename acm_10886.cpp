#include<iostream>

using namespace std;

int main()
{
    int num,tmp;

    cin>>num;
    int sum=0;
    for(int i=0;i<num;i++)
    {
        cin>>tmp;
        if(tmp==1)
            sum++;
    }
    if(sum>num-sum)
        cout<<"Junhee is cute!"<<endl;
    else
        cout<<"Junhee is not cute!"<<endl;
}