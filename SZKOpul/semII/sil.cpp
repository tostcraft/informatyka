#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <chrono>

using std::cin;
using std::cout;
using std::vector;
typedef long long huge;

int search_for_sum(huge num, int s, int e, vector<huge> &arr)
{
    if(s==e){
        if(arr[s]<num) return s+1;
        else return s;
    }
    else{
        int mid = (e+s)/2;
        if(arr[mid]>num){
            return search_for_sum(num, s, mid, arr);
        }
        else return search_for_sum(num, mid+1, e, arr);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // std::ofstream temp("stronk.txt");
    // auto starttime = std::chrono::steady_clock::now();
    vector<huge> factorials;
    huge fact = 1;
    for (int i = 1; i <= 16; i++)
    {
        fact *= i;
        factorials.push_back(fact);
    }

    vector<huge> sums;
    vector<huge> strong;

    int code = 1;
    huge big_sum = 0;
    while (true)
    {
        huge sum = 0;
        int index = 0;
        int copy_code = code;
        while (copy_code > 0)
        {
            sum += factorials[index] * (copy_code % 2);
            copy_code /= 2;
            index++;
        }
        sums.push_back(big_sum);
        strong.push_back(sum);
        if (sum > 10000000000000)
        {
            // cout <<code <<" " <<sum <<" " <<big_sum <<"\n";
            break;
        }
        // temp << sum << ": " << big_sum << "\n";
        big_sum += sum;
        code++;
    }

    // auto midtime = std::chrono::steady_clock::now();

    // cout <<std::chrono::duration_cast<std::chrono::milliseconds>(midtime-starttime).count() <<" ms\n";

    // cout <<"done\n";
    // temp <<"};";

    // temp.close();

    int n;
    cin >> n;
    // int correct = 0;
    // int incorrect = 0;

    for (int i = 0; i < n; i++)
    {

        huge a, b;
        cin >> a;
        cin >> b;
        // auto starttime_loop = std::chrono::steady_clock::now();
        int index_a = search_for_sum(a, 0, strong.size() - 1, strong);
        if (a == 1)
            index_a = 0;
        if (index_a == strong.size())
            index_a = strong.size() - 1;
        int index_b = search_for_sum(b, 0, strong.size() - 1, strong);
        if (index_b == strong.size())
            index_b = strong.size() - 1;

        // huge stupid_sum = 0;
        // for (int i = index_a; strong[i] <= b; i++)
        // {
        //     if (strong[i] >= a)
        //     {
        //         stupid_sum += strong[i];
        //     }
        // }

        // cout << index_b << " " << index_a << "\n";
        huge sum_a = sums[index_a];
        huge sum_b = sums[index_b];

        huge sum_between = sum_b - sum_a;
        cout <<sum_between <<"\n";


        // cout << sum_b << " " << sum_a << "\n";
        // cout << sum_between << " : " << stupid_sum;
        // if (sum_between == stupid_sum)
        //     correct++;
        // else {
        //     cout <<"BAD: ";
        //     cout <<a <<" " <<b <<" | ";
        //     cout << sum_between << " : " << stupid_sum <<"\n";
        //     incorrect++;
        // }

            // cout << " OK";
        // cout << "\n";
        // auto endtime_loop = std::chrono::steady_clock::now();
        // cout <<std::chrono::duration_cast<std::chrono::milliseconds>(endtime_loop-starttime_loop).count() <<" ms\n";
    }
    // cout <<"OK: " <<correct <<"\n" <<"BAD: " <<incorrect;

    return 0;
}