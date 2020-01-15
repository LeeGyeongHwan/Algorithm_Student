#include<iostream>

using namespace std;

int main()
{
    int num,tmp;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin>>tmp;
        for(int j=0;j<tmp;j++)
            cout<<"=";
        cout<<endl;   
    }

    return 0;
}