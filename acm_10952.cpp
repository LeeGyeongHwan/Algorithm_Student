#include<iostream>

using namespace std;

int main(){

    int A,B;
    do{
        cin>>A;
        cin>>B;
        if(A==0)
            break;
        cout<<A+B<<endl;       
    }while(A!=0);

    return 0;
}