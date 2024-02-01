#include<bits/stdc++.h>
using namespace std;

bool checkInteger(string s){
    bool flag = false;
    if((s[0] >= 'i' && s[0] <= 'n') || (s[0] >= 'I' && s[0] <= 'N')){
        for(int i = 1 ; i < s.length() ; i++){
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

bool checkShortInteger(string s){
    bool flag = false;
    if(s[0] >= '1' && s[0] <= '9'){
        for(int i = 1 ; i < s.length() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
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

bool checkLongInteger(string s){
    bool flag = false;
    if(s[0] >= '1' && s[0] <= '9'){
        for(int i = 1 ; i < s.length() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
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


void lexicalAnalyzer(string s){
    if(checkInteger(s)) cout<<s<<" is Integer Variable"<<endl;
    else if(checkShortInteger(s) && s.length() <= 4){
        // cout<<s<<endl;
        cout<<s<<" is Short Integer"<<endl;
    }
    else if(checkLongInteger(s) && s.length() > 4){
        // cout<<s<<endl;
        cout<<s<<" is a Long Integer"<<endl;
    }
    else {
        cout<<s<< " is an Invalid Input"<<endl;
    }
}



int main(){
    
    freopen("input.txt", "r", stdin);
    string s;

    while (cin >> s) {
        // cout << s << " ";
        lexicalAnalyzer(s);
    }
    return 0;

    
}