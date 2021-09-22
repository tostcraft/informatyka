#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int i = -1;
    int maxsum = -INT_MAX, sum = 0;
    int A[500000];
    do
    {
        i++;
        cin >> A[i];
    } while (A[i] != 0);


    sum = A[0];
    for (int k = 1; k < i+1; k++)
    {
        if (sum > maxsum)
            maxsum = sum;

        if(sum < 0)
        {
            sum = A[k];
            continue;
        }
        sum += A[k];

    }

    cout << maxsum << std::endl;

    return 0;
}