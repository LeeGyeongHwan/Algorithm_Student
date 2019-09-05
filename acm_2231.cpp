#include<iostream>

using namespace std;

int main(){
    int N;

    cin>>N;
    int sum=0;
    bool out = true;
    for(int i=1;i<=N;i++){
        int t=i;
        while(out){
            if((t/10)!=0){
                sum+=t%10;
                t/=10;
            }else{
                sum+=t;
                out=false;
            }
        }
        sum+=i;
        out=true;
        if(sum==N){
            cout<<i<<endl;
            return 0;
        }
        sum=0;
    }
    cout<<0<<endl;

}