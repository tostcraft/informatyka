#include<iostream>
#include<stack>
using std::cout;
using std::cin;



int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        std::string s;
        cin >>s;
        std::stack<char> nawiasy;
        for(char c: s){
            if(c== '<' || c=='(' || c=='{' || c=='['){
                nawiasy.push(c);
            }
            else{
                if(nawiasy.empty()){
                    nawiasy.push('#');
                    break;
                }
                switch(c){
                    case '>':
                    if(nawiasy.top() == '<'){
                        nawiasy.pop();
                    }
                    break;
                    case ')':
                    if(nawiasy.top() == '('){
                        nawiasy.pop();
                    }
                    break;
                    case '}':
                    if(nawiasy.top() == '{'){
                        nawiasy.pop();
                    }
                    break;
                    case ']':
                    if(nawiasy.top() == '['){
                        nawiasy.pop();
                    }
                    break;
                    default: break;
                }
            }
        }
        if(nawiasy.empty()){
            cout <<"T\n";
        }
        else{
            cout <<"N\n";
        }
    }
    
    return 0;
}