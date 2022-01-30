#include<bits/stdc++.h>
using std::cout;
using std::cin;


int main()
{
    std::ifstream file("lekcja-11-01-22+systemy_liczbowe/liczby.txt");
    std::ofstream out("lekcja-11-01-22+systemy_liczbowe/wynik6_3.txt");

    long int line;
    int c = 0;
    while(file >> line)
    {
        if(line%10 == 2)
        {
            line/=10;
            if(line%10==0)c++;
        }
    }
    cout <<c <<"\n";
    out << c;
    file.close();
    out.close();
    return 0;
}