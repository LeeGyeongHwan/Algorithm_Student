#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    int max=0;
    vector<int> intarr;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        intarr.push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum=intarr[i]+intarr[j]+intarr[k];
                if(sum<=m){
                    if(sum>max)
                        max=sum;
                }
            }
        }
    }
    cout<<max<<endl;

}