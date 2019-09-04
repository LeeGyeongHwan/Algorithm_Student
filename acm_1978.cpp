#include<iostream>
using namespace std;



int main()
{
    int num;
    int a;
    int numcount=0;
    cin>>num;

    for(int i=0;i<num;++i){        
        cin>>a;
        int count=0;
        for(int j=1;j<a;j++)
        {
            if(a%j==0)
                count++;
        }
        if(count==1)
            numcount++;
    }
    cout<<numcount<<endl;

    return 0;
}