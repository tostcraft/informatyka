#include<iostream>
#include<algorithm>
using std::cout;
using std::cin;


int main()
{

    std::string s1, s2;
    cin >>s1;
    cin >>s2;

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    if(s1==s2){
        cout <<"TAK";
    }
    else{
        cout <<"NIE";
    }

    cout <<"\n";
    return 0;
}