#include<bits/stdc++.h>
using std::cout;
using std::cin;

int binary_search(std::vector<int> arr, int start, int stop, int n)
{
    while(start!=stop)
    {
        int pos = (stop-start)/2+start;
        if(arr[pos]==n)return pos;
        if(arr[pos]>n)
        {
            stop = pos-1;
        }
        else
        {
            start = pos+1;
        }
    }
    return start;
}


int main()
{

    int n, a;
    cin >>n;
    std::vector<int> bierki={};

    for(int i = 0; i<n; i++)
    {
        cin >>a;
        bierki.push_back(a);
    }
    std::sort(bierki.begin(), bierki.end());
    int top1 = bierki[n-1];
    for(int i = n-2; i>-1; i--)
    {
        int search = top1-bierki[i]+1;
        a = binary_search(bierki, 0, n-1, search);
        if(bierki[a]!=search)
            break;
    }
    
    cout <<n-a <<"\n";

    


    return 0;
}