#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    string str;
    vector<string> strVec;
    cin>>num;
    getline(cin,str);
    for(int i=0;i<num;i++)
    {
        getline(cin,str);
        if(str[0]>=97)
            cout<<char(str[0]-32);
        else
            cout<<str[0];
        for(int j=1;j<str.size();j++)
        {
            cout<<str[j];
        }
        cout<<"\n";
    }
    return 0;

}