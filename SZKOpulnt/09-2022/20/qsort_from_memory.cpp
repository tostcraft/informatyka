#include <iostream>
#include <random>

using std::cin;
using std::cout;

int *make_ranodm_arr(int n, int max)
{
    srand(time(NULL));
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int val = random();
        arr[i] = val % max - max / 2;
    }
    return arr;
}

void print_arr(int *arr, int n, int s)
{
    for (int i = s; i < s + n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int partition(int arr[], int begin, int end)
{
    int pivot = arr[begin];

    int count = 0;
    for (int i = begin+1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivot_id = begin + count;
    std::swap(arr[pivot_id], arr[begin]);

    cout << pivot << " " << pivot_id << "\n";
    print_arr(arr, end-begin + 1, begin);

    int marker1 = begin, marker2 = end;

    while (marker1 < pivot_id && marker2 > pivot_id)
    {
        while (arr[marker1] <= pivot)
            marker1++;
        while (arr[marker2] > pivot)
            marker2--;
        if (marker1 < pivot_id && marker2 > pivot_id)
        {
            std::swap(arr[marker1], arr[marker2]);
            marker1++;
            marker2--;
        }
    }
    return pivot_id;
}

void qsort(int arr[], int front, int end)
{
    if (front < end)
    {
        int pivot_id = partition(arr, front, end);
        qsort(arr, front, pivot_id - 1);
        qsort(arr, pivot_id + 1, end);
    }
}

int main()
{
    srand(time(NULL));
    int n, a;
    cin >> n;
    cin >> a;

    int *arr = make_ranodm_arr(n, a);
    print_arr(arr, n, 0);
    qsort(arr, 0, n);
    // int pivot = partition(arr, 0, n - 1);
    // print_arr(arr, n, 0);
    // partition(arr, 0, pivot - 1);
    // print_arr(arr, n, 0);
    // partition(arr, pivot + 1, n - 1);
    print_arr(arr, n, 0);

    return 0;
}