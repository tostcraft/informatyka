#include<bits/stdc++.h>
using std::cout;
using std::cin;

const int WORDSIZE = 100;

void print_arr2D(int  arr[][WORDSIZE+1], int startx, int endx, int starty, int endy)
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
    std::string word1;
    std::string word2;
    int numbers[WORDSIZE+1][WORDSIZE+1] = {0};

    cin >>word1;
    cin >>word2;

    for(int i = 1; i<=word2.size(); i++)
    {
        for(int j = 1; j<=word1.size(); j++)
        {
            if(word1[j-1]==word2[i-1])
            {
                numbers[i][j] = numbers[i-1][j-1]+1;
            }
            else
            {
                numbers[i][j] = std::max(numbers[i-1][j], numbers[i][j-1]);
            }
        }
    }

    int w = numbers[word2.size()][word1.size()];
    cout <<w <<"\n";
    int marker1 = word1.size(), marker2 = word2.size();
    char * outcome = new char[w];
    int it = 0;
    while(marker1>0 && marker2>0)
    {
        if(numbers[marker2][marker1]==numbers[marker2-1][marker1])
            marker2--;
        else if(numbers[marker2][marker1]==numbers[marker2][marker1-1])
            marker1--;
        else
        {
            outcome[it] = word2[marker2-1];
            marker2--;
            marker1--;
            it++;
        }
    }
    for(int i = w-1; i>=0; i--)
    {
        cout <<outcome[i];
    }
    cout <<"\n";
    return 0;
}