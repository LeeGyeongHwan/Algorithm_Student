#include<iostream>

using namespace std;

int main()
{
    int testCase;
    string str;

    cin>>testCase;
    for (int i = 0; i < testCase; i++)
    {
        cin>>str;
        cout<<str.front()<<str.back()<<endl;
    }
    return 0; 
}