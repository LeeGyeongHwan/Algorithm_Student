#include<iostream>
using namespace std;

int main()
{
    int M,N;

    cin>>M;
    cin>>N;
    int sum=0;
    int min;
    int count=0;
    for(int i=M;i<=N;++i)
    {
        int numcount=0;
        for(int j=1;j<i;j++)
        {
            if(i%j==0)
            {
                numcount++;
            }
        }
        if(numcount==1)
        {
            sum+=i;
            if(count==0)
            {
                min=i;
                count++;
            }
        }
    }
    if(count==0){
        cout<<"-1"<<endl;
    }else{
        cout<<sum<<endl;
        cout<<min<<endl;
    }
    return 0;
}