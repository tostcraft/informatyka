#include<iostream>
using std::cout;
using std::cin;

char encode(char c, int offset){
    return (c-'A'+offset%26)%26+'A';
}

bool is_faulty(std::string uncoded, std::string encoded){
    int susoffset;
    for(int i = 0; i<26; i++){
        if(encode(uncoded[0], i) == encoded[0]){
            susoffset = i;
            break;
        }
    }
    for(int i = 1; i<uncoded.size(); i++){
        if(encode(uncoded[i], susoffset)!=encoded[i]){
            return true;
        }
    }
    return false;
}

int main()
{
    std::string s1, s2;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin >>s1;
        cin >>s2;
        if(is_faulty(s1, s2)) cout <<s1 <<"\n";
    }
    
    cout <<"\n";
    return 0;
}