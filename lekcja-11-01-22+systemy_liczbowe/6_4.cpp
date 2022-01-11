#include<bits/stdc++.h>
using std::cout;
using std::cin;

long int todec(int n)
{
    long int a = 0;
    int i = 0;
    while(n>0)
    {
        a+=std::pow(8, i) * (n%10);
        n/=10;
        i++;
    }
    return a;
}

int main()
{
    std::ifstream file("lekcja-11-01-22+systemy_liczbowe/liczby.txt");
    std::ofstream out("lekcja-11-01-22+systemy_liczbowe/wynik6_4.txt");

    long int line;
    long int c = 0;
    while(file >> line)
    {
        if(line%10 == 8)
        {
            c+=todec(line/10);
        }
    }
    cout <<c <<"\n";
    out << c;
    file.close();
    out.close();
    return 0;
}