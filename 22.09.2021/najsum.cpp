#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main()
{
    int i = -1;
    int maxsum = -INT_MAX, sum = 0;
    int A[500000];
    do
    {
        i++;
        cin >> A[i];
    } while (A[i] != 0);

    for (int j = 0; j < i; j++)
    {
        sum = 0;
        for (int k = j; k < i; k++)
        {
            sum += A[k];
            if (sum > maxsum)
                maxsum = sum;
        }
    }
    cout << maxsum << std::endl;

    return 0;
}