#include<bits/stdc++.h>
using std::cout;
using std::cin;

const int ARRSIZE = 100;

void print_arr2D(int  arr[][ARRSIZE+1], int startx, int endx, int starty, int endy)
{
    for(int i = starty; i<endy; i++)
    {
        for(int j = startx; j<endx; j++)
        {
            cout <<arr[i][j] <<" ";
        }
        cout <<"\n";
    }
}

int main()
{
    std::string n, m;
    std::string arr1[ARRSIZE];
    std::string arr2[ARRSIZE];
    int len1 = 0, len2 = 0;
    int lengths[ARRSIZE+1][ARRSIZE+1]={0};

    std::getline(cin, n);
    std::getline(cin ,m);

    for(int i = 0; i<n.size(); i++)
    {
        std::string s = "";
        for(i; n[i]!=' ' && i<n.size();i++)
        {
            s+=n[i];
        }
        arr1[len1] = s;
        len1++;
    }
    for(int i = 0; i<m.size(); i++)
    {
        std::string s = "";
        for(i; m[i]!=' ' && i<m.size();i++)
        {
            s+=m[i];
        }
        arr2[len2] = s;
        len2++;
    }

    for(int i = 1; i<=len2; i++)
    {
        for(int j = 1; j<=len1; j++)
        {
            if(arr1[j-1]==arr2[i-1])
            {
                lengths[i][j] = lengths[i-1][j-1]+1;
            }
            else
            {
                lengths[i][j] = std::max(lengths[i][j-1], lengths[i-1][j]);
            }
        }
    }
    int w = lengths[len2][len1];
    int marker1 = len1, marker2 = len2;
    std::string * outcome = new std::string[w];
    int it = 0;
    while(marker1>0 && marker2>0)
    {
        if(lengths[marker2][marker1]==lengths[marker2-1][marker1])
            marker2--;
        else if(lengths[marker2][marker1]==lengths[marker2][marker1-1])
            marker1--;
        else
        {
            outcome[w-it-1] = arr2[marker2-1];
            marker2--;
            marker1--;
            it++;
        }
    }
    for(int i = 0; i<w; i++)
    {
        cout <<outcome[i] <<" ";
    }
    cout <<"\n";


    return 0;
}