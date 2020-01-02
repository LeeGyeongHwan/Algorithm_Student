#include<iostream>

using namespace std;

int main()
{
    int num;
    string str;
    cin>>num;
    getline(cin,str);
    for(int i=1;i<=num;i++)
    {
        getline(cin,str);
        cout<<i<<". "<<str<<endl;
    }

    return 0;
}