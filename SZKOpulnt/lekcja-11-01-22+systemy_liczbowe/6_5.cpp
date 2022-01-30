#include<bits/stdc++.h>
using std::cout;
using std::cin;

long int todec(int n, int base)
{
    long int a = 0;
    int i = 0;
    while(n>0)
    {
        a+=std::pow(base, i) * (n%10);
        n/=10;
        i++;
    }
    return a;
}


int main()
{
    std::ifstream file("lekcja-11-01-22+systemy_liczbowe/liczby.txt");
    std::ofstream out("lekcja-11-01-22+systemy_liczbowe/wynik6_5.txt");

    long int line;
    long int codes[2] = {0, 0};
    long int maxmin[2] = {LONG_MIN, LONG_MAX};
    while(file >> line)
    {
        int num = todec(line/10, line%10);
        if(num>maxmin[0])
        {
            maxmin[0] = num;
            codes[0] = line;
        }
        else if(num<maxmin[1])
        {
            maxmin[1] = num;
            codes[1] = line;
        }
    }
    cout <<"max: " <<codes[0] <<" " <<maxmin[0] <<"\n" <<"min: " <<codes[1] <<" " <<maxmin[1] <<"\n";
    out <<"max: " <<codes[0] <<" " <<maxmin[0] <<"\n" <<"min: " <<codes[1] <<" " <<maxmin[1] <<"\n";
    file.close();
    out.close();
    return 0;
}