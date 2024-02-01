#include<bits/stdc++.h>
using namespace std;

int precedings(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*'||ch == '/'){
        return 2;
    }
    else if(ch == '^'){
        return 3;
    }
    else return 0;
}

// string infixToPostfix(string s){
//     stack<char>stk;
//     stk.push('#');
//     string postfix = "";
//     string::iterator it;
//     for(it = s.begin() ; it != s.end() ; it++){
//         if(isalnum(char(*it))) postfix += *it;
//         else if(*it == '('){
//             stk.push('(');
//         }
//         else if(*it == '^'){
//             stk.push('^');
//         }
//         else if(*it == ')'){
//             while(stk.top() != '#' && stk.top() !=  '('){
//                 postfix += stk.top();
//                 stk.pop();
//             }
//             stk.pop();
//         }
//         else{
//             if(precedings(*it) > precedings(stk.top())){
//                 stk.push(*it);
//             }
//             else{
//                 while(stk.top() != '#' && precedings(*it) <= precedings(stk.top())){
//                     postfix += stk.top();
//                     stk.pop();
//                 }
//                 stk.push(*it);
//             }
//         }
//     }

//     while(stk.top() != '#'){
//         postfix += stk.top();
//         stk.pop();
//     }
//     return postfix;
// }

string infixToPostfix(string s){
    stack<char>stk;
    stk.push('#');
    string postfix = "";
    string::iterator it;
    for(it = s.begin() ; it != s.end() ; it++){
        if(isalnum(char(*it))) postfix += *it;
        else if(*it == '('){
            stk.push('(');
        }
        else if(*it == '^'){
            stk.push('^');
        }
        else if(*it == ')'){
            while(stk.top() != '#' && stk.top() != '('){
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            if(precedings(*it) > precedings(stk.top()))stk.push(*it);
            else{
                while(stk.top() != '#' && precedings(*it) <= precedings(stk.top())){
                    postfix += stk.top();
                    stk.pop();
                }
            }
        }
    }
    while(stk.top() != '#'){
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}

int main(){

    string s = "(A-B)*(D/E)";
    cout<<infixToPostfix(s)<<endl;
}

