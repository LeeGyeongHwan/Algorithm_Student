#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;

    cin>>str;
    int count=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='j' && i!=0){
            if(str[i-1] == 'l') count--;
            if(str[i-1] == 'n') count--;
        }
        if(str[i]=='-') count--;
        if(str[i]=='=' && i!=0){
            if(str[i-1]=='s') count--;
            if(str[i-1]=='z' && i>1){
                if(str[i-2]=='d') count-=2;
                else count--;
            }else if(str[i-1]=='z') count--;
            if(str[i-1]=='c') count--;
        }
        count++;
    }
    
    cout<<count<<endl;


    return 0;
}