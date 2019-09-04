#include<iostream>

using namespace std;
int zero=0;
int one=0;
int fibo(int n){
    if(n==0){
        zero++;
        return 0;
    }else if(n==1){
        one++;
        return 1;
    }else{
        return fibo(n-1)+fibo(n-2);
    }

}

int main()
{
    int N;
    int num;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        fibo(num);
        cout<<zero<<" "<<one<<endl;
        zero=0;
        one=0;
    }


    return 0;
}