#include<bits/stdc++.h>
using namespace std;

bool floatVariableCheck(string s){
    bool flag = false;
    // cout<<"float variable check : "<<s<<" : ";
    if((s[0] >= 'a' && s[0] <= 'h') || (s[0] >= 'A' && s[0] <= 'H') || (s[0] >= 'o' && s[0] <= 'z') || (s[0] >= 'O' && s[0] <= 'Z')){
        for(int i = 1 ; i < s.length() ; i++){
            if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z') ||(s[i] >= '0' && s[i] <= '9')){
                flag = true;
            }
            else{
                flag = false;
                return flag;
            }
        }
    }
    // cout<<flag<<endl;
    return flag;
}

bool LeftCheck(string sLeft){
    bool flag = false;
    if(!(sLeft[0] >= '0' && sLeft[0] <= '9')){
        flag = false;
    }
    else if(sLeft[0] == '0'){
        flag = true;
    }
    else if(sLeft[0] >= '1' && sLeft[0] <= '9'){
        for(int i = 1 ; i < sLeft.length() ; i++){
            if(sLeft[i] >= '0' && sLeft[i] <= '9'){
                flag = true;
            }
            else {
                flag = false;
                return flag;
            }
        }
    }
    return flag;
}
bool floatNumberRightCheck(string sRight){
    bool flag = false;
    for(int i = 0 ; i < 2 ; i++){
        if(sRight[i] >= '0' && sRight[i] <= '9'){
            flag = true;
        }
        else{
            flag = false;
            return flag;
        }
    }
    return flag;
}

bool doubleNumberRightCheck(string sRight){
    bool flag = false;
    for(int i = 0 ; i < sRight.length() ; i++){
        if(sRight[i] >= '0' && sRight[i] <= '9'){
            flag = true;
        }
        else{
            flag = false;
            return flag;
        }
    }
    return flag;
}

void lexicalAnalyzer(string s){
    string ssLeft = "";
    string ssRight = "";
    string ss = "";
    int tmpInd = -1;
    for(int i = 0 ; i < s.length() ; i++){
       if(s[i] == '.'){
        tmpInd = i;
        break;
       }
       else{
        ss += s[i];
       }
    }

    if(tmpInd != -1){
        for(int i = 0 ; i < tmpInd ; i++){
            ssLeft += s[i];
        }
        for(int i = tmpInd+1 ; i < s.length() ; i++){
            ssRight += s[i];
        }
    }
    
    // cout<<"ss = "<<ss<<" "<<"ssLeft = "<<ssLeft<<" "<<"ssRight = "<<ssRight<<endl;
    if(ss.length() == s.length()){
        // cout<<ss<<endl;
        if(floatVariableCheck(ss))
            cout<<s<<" is a float variable"<<endl;
        else cout<<s<<" is an invalid input"<<endl;
        
    }
    
    else if(ssRight.length() <= 2){
        // cout<<"float number check: "<<s<<endl;
        if(LeftCheck(ssLeft) && floatNumberRightCheck(ssRight)){
            cout<<s<<" is a float Number"<<endl;
        }
        else{
        cout<<s<<" is an invalid input"<<endl;
        }
    }

    else if(ssRight.length() > 2){
        if(LeftCheck(ssLeft) && doubleNumberRightCheck(ssRight)){
            cout<<s<<" is a double number"<<endl;
        }
        else{
            cout<<s<<" is an invalid input"<<endl;
        }
    }
    


}

int main(){
    freopen("input.txt","r",stdin);
    string s;
    while(cin>>s){
        // cout<<s<<endl;
        lexicalAnalyzer(s);
        cout<<endl;
    }
}