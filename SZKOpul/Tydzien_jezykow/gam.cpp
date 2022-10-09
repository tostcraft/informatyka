#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;

long game(std::vector<int> seq, int P)
{

    long result;

    std::vector<int> set;
    for (int i = 0; i < P; i++)
    {
        set.push_back(seq.front());
        seq.erase(seq.begin());
    }

    long alice = 0, bob = 0;
    int turn = 0;

    while (!set.empty())
    {
        auto max_it = std::max_element(set.begin(), set.end());
        int max_pos = std::distance(set.begin(), max_it);
        int max_val = set[max_pos];


        (turn % 2 == 0) ? alice += max_val : bob += max_val;

        set.erase(max_it);

        if(!seq.empty()){
            set.push_back(seq.front());
            seq.erase(seq.begin());
        }
        turn++;
    }

    result = alice - bob;

    return result;
}

int main()
{

    int N, K;
    cin >>N; cin >>K;

    std::vector<int> data;
    for(int i = 0; i<N; i++){
        int a;
        cin >>a;
        data.push_back(a);
    }

    for(int i = 0; i<K; i++)
    {
        int P;
        cin >>P;

        long result = game(data, P);
        cout <<result <<"\n";
    }
    
    return 0;
}