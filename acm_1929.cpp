#include<iostream>

using namespace std;

int main()
{
    int M,N;
    bool isChecked[1000001];
    cin>>M>>N;
    //에라토스테네스의 체
    for(int i=2;i<=N;i++)
    {
        if(isChecked[i]==false)
        {
            if(i>=M)
                cout<<i<<"\n";
            for(int j=i+i;j<=N;j+=i)
            {
                isChecked[j]=true;
            }
        }
    }

    return 0;
}