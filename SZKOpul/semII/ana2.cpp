#include<iostream>
#include<algorithm>
using std::cout;
using std::cin;


int main()
{

    int n;
    cin >>n;
    std::string s1, s2;
    for(int i = 0;i<n;i++){
        cin >>s1;
        cin >>s2;
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        if(s1==s2){
            cout <<"TAK\n";
        }
        else{
            cout <<"NIE\n";
        }
    }
    

    cout <<"\n";
    return 0;
}