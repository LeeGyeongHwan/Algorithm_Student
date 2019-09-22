#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int tmp;
    vector<int> abc;
    string str;
    
    for(int i=0;i<3;i++)
    {
        cin>>tmp;
        abc.push_back(tmp);
    }
    sort(abc.begin(),abc.end());
    
    cin>>str;
    for(int j=0;j<str.size();j++)
    {
        switch (str[j])
        {
        case 'A':cout<<abc[0]<<" ";
            break;
        case 'B':cout<<abc[1]<<" ";
            break;
        case 'C':cout<<abc[2]<<" ";
        }
    }
   
    

    return 0;
}