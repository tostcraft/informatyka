#include <bits/stdc++.h>

using std::cin; 
using std::cout; 
using std::string;

string ALFABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int n, key;
    string Sin, Sout;
    cin >> n >>key;
    for(int i = 0; i<n; i++)
    {
        Sout = "";
        cin >> Sin;
        int len = Sin.length();
        for(int j = 0; j<len; j++)
        {
            char a = Sin[j];
            int ascii = (int)a-65;
            a = ALFABET[(ascii+key)%26];
            Sout += a;
        }
        cout << Sout <<std::endl;
    }
    return 0;
}