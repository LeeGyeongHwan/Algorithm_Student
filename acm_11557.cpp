#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<string,int> a,pair<string,int> b)
{
    if(a.second < b.second)
        return true;
    else
        return false;
}

int main()
{
    int testCase,num;
    string str;
    int tmp;
    vector<pair<string,int> > pVec;

    cin>>testCase;
    for(int i=0;i<testCase;i++)
    {
        cin>>num;
        for(int j=0;j<num;j++)
        {
            cin>>str>>tmp;
            pVec.push_back(make_pair(str,tmp));
        }
        sort(pVec.begin(),pVec.end(),compare);
        cout<<pVec.back().first<<endl;
        pVec.clear();
    }


    return 0;
}