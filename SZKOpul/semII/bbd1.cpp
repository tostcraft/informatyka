#include<iostream>
using std::cout;
using std::cin;


char encode(char c, int offset){
    return (char)((c-'A'+offset)%26+'A');
}

int main()
{
    std::string s;
    int n, offset;
    cin >>n;
    cin >>offset;
    for(int i = 0; i<n; i++){
        cin>>s;
        for(int j = 0; j<s.size(); j++){
            s[j] = encode(s[j], offset);
        }
        cout <<s <<"\n";
    }
    
    return 0;
}