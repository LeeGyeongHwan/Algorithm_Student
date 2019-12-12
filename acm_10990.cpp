#include <iostream>

using namespace std;

int main()
{ 
    
    int starNum;
    cin >> starNum;

    for (int a = 0; a < starNum; a++)
    {
        for(int i=0;i<starNum-a-1;i++)
            cout<<" ";
        for(int i=0;i<(2*a+1);i++)
        {
            if(i==0||i==2*a)
                cout<<"*";
            else
                cout<<" ";
        }
        cout << endl;
    }



    return 0;
}