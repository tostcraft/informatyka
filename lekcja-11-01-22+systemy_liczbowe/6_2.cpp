#include<bits/stdc++.h>
using std::cout;
using std::cin;


bool nozeros(long int n)
{
    while(n>0)
    {
        if(n%10==0)return false;
        n/=10;
    }
    return true;
}

int main()
{
    std::ifstream file("lekcja-11-01-22+systemy_liczbowe/liczby.txt");
    std::ofstream out("lekcja-11-01-22+systemy_liczbowe/wynik6_2.txt");

    long int line;
    int c = 0;
    while(file >> line)
    {
        if(line%10 == 4) 
        {
            if(nozeros(line))
            {
                c++;
            }
        }
    }
    cout <<c <<"\n";
    out << c;
    file.close();
    out.close();
    return 0;
}