#include<iostream>
#include<stack>
//na stos, rzuciliśmy
//nasz plusa los
//na stos
//na stos

using std::cin;
using std::cout;

bool is_in(char c, std::string s){
    for(char a:s){
        if(a==c){
            return true;
        }
    }
    return false;
}

int main(){

    std::string trad_notation;
    std::getline(cin, trad_notation);
    
    std::stack<char> operator_stack;
    std::string onp_notation;

    for(char c: trad_notation){
        if(!is_in(c, "+-*/()")){
            onp_notation+=c;
            continue;
        }

        if(c!=')'){
            if(c=='+' || c=='-'){
                while(!operator_stack.empty() && operator_stack.top()!='('){
                    onp_notation+=operator_stack.top();
                    operator_stack.pop();
                }
            }
            else if(c=='*' || c=='/'){
                while(!operator_stack.empty() && !is_in(operator_stack.top(), "+-(")){
                    onp_notation+=operator_stack.top();
                    operator_stack.pop();
                }
            }
            operator_stack.push(c);
        }
        else{
            while(!operator_stack.empty() && operator_stack.top() != '('){
                onp_notation+=operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.pop();
        }

    }
    while(!operator_stack.empty()){
        onp_notation+=operator_stack.top();
        operator_stack.pop();
    }
    cout <<onp_notation <<"\n";

    return 0;
}