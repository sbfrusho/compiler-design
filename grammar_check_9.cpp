#include<bits/stdc++.h>
using namespace std;

vector<string>PN = {"Sagor","Selim","Salma","Nipu","he","she","I","we","you","they"};
vector<string>N = {"book","cow","dog","home","grass","rice","mango"};
vector<string>V = {"read","eat","take","run","write"};

bool checkFirstword(string s){
    for(auto it : PN){
        if(it == s)return true;
    }
    return false;
}

bool checkVerb(string s){
    for(auto it : V){
        if(it == s)return true;
    }
    return false;
}

bool checkLastWord(string s){
    for(auto it : N){
        if(it == s)return true;
    }
    return false;
}

int main(){
    freopen("input.txt","r",stdin);
    string s;

    vector<string>words;
    string word = "";
    while(getline(cin,s)){
        s += " ";
        for(int i = 0 ; i < s.length() ; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                word += s[i];
            }
            else if(s[i] == ' '){
                words.push_back(word);
                word = "";
            }
        }
    }
//     for(auto it : words){
//         cout<<it<<endl;
//     }

    

    if(checkFirstword(words[0]) && checkVerb(words[1]) && checkLastWord(words[2])){
        cout<<"Valid sentence"<<endl;
    }
    else{
        cout<<"Invalid sentence"<<endl;
    }
    
}