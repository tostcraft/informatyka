#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;

void print_arr_2d(long **arr, int startx, int starty, int stopx, int stopy){
    for (int i = starty; i < stopy; i++){
        for (int j = startx; j < stopx; j++){
            cout << std::right << std::setw(4) << arr[i][j];
        }
        cout << "\n";
    }
}

struct item{
    unsigned long long mass;
    unsigned long long value;
} foo;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n;
    cin >> k;

    item *items = new item[10001];
    for (int i = 1; i <= n; i++){
        cin >> items[i].mass;
        cin >> items[i].value;
    }

    unsigned long long **values = new unsigned long long *[10001];
    for (int i = 0; i < 10001; i++){
        values[i] = new unsigned long long[501]{0LL};
    }


    for (long long int i = 1; i <= n; i++){

        for (long long int j = 1; j <= k; j++){

            //solution to the subproblem without current item
            unsigned long long previous_best = values[i - 1][j];

            if (j < items[i].mass){
                values[i][j] = previous_best;
                continue;
            }

            //current items value plus the solution to the subproblem with max mass lowered by items mass
            unsigned long long previous_plus_current = items[i].value + values[i - 1][j - items[i].mass];
            if (previous_plus_current >= previous_best){
                values[i][j] = previous_plus_current;
            }
            else{
                values[i][j] = previous_best;
            }
        }
    }

    // cout <<"\n";
    // print_arr_2d(values, 0, 0, k+1, n+1);
    unsigned long long outcome = values[n][k];
    std::free(values);
    std::free(items);

    cout << outcome;

    return 0;
}
