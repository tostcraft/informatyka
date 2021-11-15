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
    int n, m;
    int arr1[ARRSIZE];
    int arr2[ARRSIZE];
    int pointers[ARRSIZE] = {0};
    int lengths[ARRSIZE+1][ARRSIZE+1]={0};
    
    cout <<"length of the first array(max " <<ARRSIZE <<"): "; cin >>n;
    cout <<"input first array:\n";
    for(int i = 0; i<n; i++)
        cin >>arr1[i];
    
    cout <<"length of the second array(max " <<ARRSIZE <<"): "; cin >>m;
    cout <<"input second array:\n";
    for(int i = 0; i<m; i++)
        cin >>arr2[i];
    

    for(int i = 1; i<=m; i++)
    {
        int maxlen = 0;
        for(int k = 0; k<i; k++)
        {
            if(arr2[k-1]<arr2[i-1] && lengths[k][n]>maxlen)
            {
                maxlen = lengths[k][n];
                pointers[i] = k;
            }
        }
        for(int j = 1; j<=n; j++)
        {
            if(arr1[j-1]==arr2[i-1])
            {
                lengths[i][j] = lengths[pointers[i]][j-1]+1;
            }
            else
            {
                lengths[i][j] = std::max(lengths[i][j-1], lengths[pointers[i]][j]);
            }
        }
    }
    int maxlen = 0, fp = 0;
    for(int i = 1; i<=m; i++)
    {
        if(lengths[i][n]>maxlen)
        {
            maxlen = lengths[i][n];
            fp = i;
        }
    }
    int * outcome = new int[maxlen];
    for(int i = maxlen-1; i>=0; i--)
    {
        outcome[i] = arr2[fp-1];
        fp = pointers[fp];
    }
    cout <<"\n";
    
    for(int i = 0; i<maxlen; i++)
    {
        cout <<outcome[i] <<" ";
    }
    cout <<"\n";


    return 0;
}