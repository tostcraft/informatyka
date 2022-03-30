#include<bits/stdc++.h>
using std::cout;
using std::cin;



class QSortArray
{
    private:
        int * arr = new int[10];
        int len = 10;

    public:
    void setsize(std::istream stream)
    {
        stream >>len;
        arr = new int[len];
    }
    void setsize(int newsize)
    {
        len = newsize;
        arr = new int[len];
    }

    int size()
    {
        return len;
    }
    void setarr(int newlen, int * newarr)
    {
        arr = newarr;
        len = newlen;
    }

    void setarr(int newlen, int bottom, int dif)
    {
        len = newlen;
        arr = new int[len];
        std::srand(time(NULL));
        for(int i = 0; i<len; i++)
        {
            arr[i] = rand()%dif+bottom;
        }
    }
    void getarr(std::istream stream)
    {
        for(int i = 0; i<len; i++)
        {
            stream >> arr[i];
        }
    }

    void print()
    {
        for(int i = 0; i<len; i++)
        {
            cout <<arr[i] <<" ";
        }
        cout <<"\n";
    }

    int partition(int p/*start*/, int r/*end*/)
    {
        int x = arr[p];
        int i = p-1;
        int j = r+1;
        while(i<j)
        {
            do
            {
                j--;
            } while (arr[j]>x);
            do
            {
                i++;
            } while (arr[i]<x);
            
            if(i<j)
            {
                int hold = arr[i];
                arr[i] = arr[j];
                arr[j] = hold;
            }
            else
            {
                return j;
            }

        }
        return j;
    }

    void sort(int p, int r)
    {
        if(p<r)
        {
            int q = partition(p, r);
            sort(p, q);
            sort(q+1, r);
        }
    }

    
    
};




int main()
{
    QSortArray qsarr;
    int len = 30;
    int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};
    qsarr.setarr(len, 5, 200);
    qsarr.print();
    qsarr.sort(0, len-1);
    qsarr.print();

    return 0;
}