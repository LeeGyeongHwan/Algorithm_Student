#include<iostream>

using namespace std;

int main()
{
    int L,P,tmp;

    cin>>L>>P;
    int num=L*P;

    for(int i=0;i<5;i++)
    {
        cin>>tmp;
        cout<<tmp-num<<" ";
    }

    return 0;
}