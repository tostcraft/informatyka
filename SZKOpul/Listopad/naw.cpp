#include<iostream>
#include<stack>
#include<vector>
#include<fstream>
using std::cout;
using std::cin;

bool is_valid_parentheses(char * text, int s /*start check*/, int e /*end check*/){
    std::stack<int> nawiasy;
    for(int i=s; i<=e; i++){
        if(text[i]=='('){
            nawiasy.push(1);
        }
        else{
            if(nawiasy.empty()){
                return 0;
            }
            nawiasy.pop();
        }
    }
    if(nawiasy.empty()) return true;
    return false;
}


long long count_parentheses(char * text, int n){
    long long mc = 0;
    std::vector<long long> layers;
    layers.push_back(0);
    std::stack<char> nawiasy;
    for(int i = 0; i<n; i++){
        if(text[i]=='('){
            nawiasy.push('(');
            layers.push_back(0);
        }
        else{
            if(nawiasy.empty()){
                if(layers[0]==0) continue;
                else{
                    long long layer_combo = layers.back();
                    mc+=layer_combo*(layer_combo+1)/2;
                    layers[0] = 0;
                    continue;
                }
            }
            else{
                long long layer_combo = layers.back();
                mc+=layer_combo*(layer_combo+1)/2;
                layers.pop_back();
                layers.back()++;
                nawiasy.pop();
            }
        }
    }
    while(!layers.empty()){
        long long layer_combo = layers.back();
        mc+=layer_combo*(layer_combo+1)/2;
        layers.pop_back();
    }
    return mc;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin >>n;
    cin.get();
    char *s = new char[n];
    cin.getline(s, n+1);
    // for(int i = 0; i<20; i++){
    //     if(s[i]=='('){
    //         for(int j = i+1; j<20; j++){
    //             if(s[j]==')'){
    //                 if(is_valid_parentheses(s, i, j)){
    //                     c++;
    //                 }
    //             }
    //         }
    //     }
    // }
    long long c1 = count_parentheses(s, n);
    cout <<c1 <<"\n";
    
    return 0;
}