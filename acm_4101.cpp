#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A,B;

    do
    {
        cin>>A>>B;
        if(A==0 && B==0)
            break;
        if(A>B)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }while(1);
    


    return 0;
}