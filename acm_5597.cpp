#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool check[31]={false};
    int tmp;
    for(int i=0;i<28;i++)
    {
        cin>>tmp;
        check[tmp]=true;
    }
    for(int i=1;i<31;i++)
    {
        if(check[i]==false)
            cout<<i<<endl;
    }
    return 0;
}