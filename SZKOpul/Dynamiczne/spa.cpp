#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;

bool bigger_than(const int& a, const int& b){
    if(a>b) return true;
    return false;
}

int main()
{
    int * fortune = new int[150]{0};    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> fortune[i];
    }
    std::sort(fortune, fortune + n, bigger_than);
    int s1 = 0, s2 = 0;
    for (int i=0; i <n; i++)
    {
        if (s1 > s2)
        {
            s2 += fortune[i];
        }
        else
        {
            s1 += fortune[i];
        }
    }
    if (s1 > s2)
        cout << s1 << " " << s2 << "\n";
    else
        cout << s2 << " " << s1 << "\n";
    return 0;
}