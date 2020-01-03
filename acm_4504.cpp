#include<iostream>

using namespace std;

int main()
{
    int n,num;
    cin>>n;

    do{
        cin>>num;
        if(num==0)
            break;
        if(num%n!=0)
            cout<<num<<" is NOT a multiple of "<<n<<".\n";
        else
        cout<<num<<" is a multiple of "<<n<<".\n";
    }while(1);


    return 0;
}