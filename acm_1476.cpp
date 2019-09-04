#include<iostream>
using namespace std;

int main(){
    int A,B,C;

    cin>>A>>B>>C;

    int i=0;
    do{
        i++;
        int tmpA,tmpB,tmpC;
        tmpA=i%15;
        tmpB=i%28;
        tmpC=i%19;
        if(tmpA==0) tmpA=15;
        if(tmpB==0) tmpB=28;
        if(tmpC==0) tmpC=19;
        if(tmpA==A && tmpB==B && tmpC==C) break;

    }while(1);

    cout<<i<<endl;
    return 0;
}