#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    string tmp;
    do{
        getline(cin,str);
        for(int i=0;i<str.size();i++){
            tmp.push_back(str[str.size()-1-i]);
        }
        if(!str.compare("END")){
            break;
        }
        cout<<tmp<<endl;
        tmp.clear();
    }while(1);
    return 0;
}