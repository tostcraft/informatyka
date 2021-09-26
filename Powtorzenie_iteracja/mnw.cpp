#include<iostream>
using std::cin;
using std::cout;

int main()
{
    int x;
    cin >>x;
    std::string s1(x+2, '#');
    std::string s2(x, '@');
    cout <<s1 <<std::endl <<'#' <<s2 <<'#' <<std::endl <<s1 <<std::endl;
}