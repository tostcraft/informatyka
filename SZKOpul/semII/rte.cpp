#include<iostream>
using std::cout;
using std::cin;


bool equaltexts(std::string s1, std::string s2){
    if(s1==s2){
        return true;
    }
    else if(s1.size()==1){
        return false;
    }
    else{
        int len = s1.size()/2;
        std::string a1, a2, b1, b2;
        a1 = s1.substr(0, len);
        a2 = s1.substr(len, s1.size()-len);
        b1 = s2.substr(0, len);
        b2 = s2.substr(len, s1.size()-len);
        // cout <<a1 <<" " <<a2 <<" " <<b1 <<" " <<b2<<"\n";
        return ((equaltexts(a1, b1)&&equaltexts(a2, b2))||(equaltexts(a1, b2)&&equaltexts(a2, b1)));
    }
}

int main()
{
    std::string s1, s2;
    cin >>s1;
    cin >>s2;
    if(equaltexts(s1, s2))cout <<"TAK";
    else cout <<"NIE";
    cout <<"\n";
    return 0;
}