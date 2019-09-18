#include <iostream>

using namespace std;

int main()
{
    
    while(true){
        int A,B;
        cin>>A>>B;
        if(cin.eof()==true)
            break;
        cout<<A+B<<endl;
    }

    return 0;
}