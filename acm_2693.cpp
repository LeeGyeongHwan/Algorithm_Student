#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tmp;
    vector<int> intVec;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>tmp;
            intVec.push_back(tmp);
        }
        sort(intVec.begin(),intVec.end());
        cout<<intVec[7]<<"\n";
        intVec.clear();
    }


    return 0;
}