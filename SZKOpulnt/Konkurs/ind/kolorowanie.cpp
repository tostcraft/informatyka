#include<iostream>

using std::cin;
using std::cout;

int main(){

    int h, w, n;
    cin >>h;
    cin >>w;
    cin >>n;
    int *quantities = new int[n]{0};
    for(int i = 0; i<n; i++)
    {
        cin >>quantities[i];
    }

    int *board = new int[h*w]{0};
    int last_run = 0;
    for(int i = 1; i<=n; i++) //for each color
    {
        for(int j = last_run; j<last_run+quantities[i-1]; j++)
        {
            board[j] = i;
        }
        last_run+=quantities[i-1];
    }

    int marker = 0;
    for(int i=0; i<h; i++)
    {
        if(i%2==0)
        {
            for(int j = marker; j<marker+w; j++)
            {
                cout <<board[j] <<" ";
            }
            marker+=w-1;
        }
        else
        {
            for(int j = marker+w; j>marker; j--)
            {
                cout <<board[j] <<" ";
            }
            marker+=w+1;
        }
        cout <<"\n";
    }
    cout <<"\n";

    return 0;
}
