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
    
    return 0;
}