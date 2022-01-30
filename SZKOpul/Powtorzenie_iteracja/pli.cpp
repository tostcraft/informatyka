#include<bits/stdc++.h>
using std::cout;
using std::cin;

bool isPalindrom(int k)
{
    std::string s = std::to_string(k);
    int len = s.length();
    for(int i = 0; i<len/2; i++)
    {
        if(s[i]!=s[len-i-1]) return false;
    }
    return true;
}

int main()
{
    int k, i=0;
    cin >>k;
    while(!isPalindrom(k))
    {
        i++;
        k++;
    }
    cout <<i <<std::endl;
    return 0;
}