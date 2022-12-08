#include<iostream>
#include<stack>
#include<fstream>
using std::cout;
using std::cin;



int main()
{
    std::ifstream file("naw1_data.txt");
    std::ofstream output("naw1_output.txt");
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(file>>n){
        output <<"\n";
    // cin>>n;
        for(int i = 0; i<n; i++){
            std::string s;
            file >>s;
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
                output <<"T\n";
            }
            else{
                output <<"N\n";
            }
        }
    }
    file.close();
    output.close();
    
    return 0;
}