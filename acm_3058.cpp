#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int testCase,tmp;
    vector<int> intVec;
    
    
    cin>>testCase;
    for(int i=0;i<testCase;i++)
    {
        int minNum=100;
        int sum=0;
        for(int j=0;j<7;j++)
        {
            cin>>tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(),intVec.end());
        for(int j=0;j<7;j++)
        {
            if(intVec[j]%2==0)
            {
                if(intVec[j]<minNum)
                {
                    minNum=intVec[j];
                }
                sum+=intVec[j];
            }
        }
        cout<<sum<<" "<<minNum<<endl;
        intVec.clear();

    }

    return 0;
}