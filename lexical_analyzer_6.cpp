#include<bits/stdc++.h>
using namespace std;

bool varaiableCheck(string s){
    bool flag = false;
    if((s[3] >= 'a' && s[3] <= 'z') || (s[3] >= 'A' && s[3] <= 'Z') || (s[3] >= '0' && s[3] <= '9')){
        for(int i = 3 ; i < s.length() ; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                flag = true;
            }
            else{
                flag = false;
                return flag;
            }
        }
    }
    return flag;
}

bool binaryNumberCheck(string s){
    bool flag = false;
    for(int i = 1 ; i < s.length() ; i++){
        if(s[i] == '0' || s[i] == '1'){
            flag = true;
        }
        else {
            flag = false;
            return flag;
        }
    }
    return flag;
}

void lexicalAnalysis(string s){
    string ss = "";
    for(int i = 0 ; i < 3 ; i++){
        ss += s[i];
    }
    if(ss == "ch_"){
        if(varaiableCheck(s)){
            cout<<s<<" is a character variable"<<endl;
        }
        else{
            cout<<s<<" is an invalid input"<<endl;
        }
    }
    else if(ss == "bn_"){
        if(varaiableCheck(s)){
            cout<<s<<" is a binary variable"<<endl;;
        }
        else{
            cout<<s<<" is an invalid input"<<endl;
        }
    }
    else if(s[0] == '0'){
        if(binaryNumberCheck(s)){
            cout<<s<<" is a binary number"<<endl;
        }
        else {
            cout<<s<<" is an invalid input"<<endl;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    string s;
    while(cin>>s){
        lexicalAnalysis(s);
        cout<<endl;
    }
}