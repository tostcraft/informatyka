#include<iostream>
#include<array>

//work in progress

using std::cin; using std::array; using std::cout;


int main(){
    int gardensize;
    array<int, 1000000> garden = {0};
    int inrow;
    
    cin >> gardensize;
    cin >> inrow;
    for(int i = 0; i<gardensize; i++){
        cin >> garden[i];
    }

    bool found_one = false;
    int head = -1, tail = 0;
    int sum = 0;
    int best = 1000000;
    while(head < gardensize){
        if(sum <= inrow){
            head ++;
            sum+=garden[head];
        }
        else{
            sum-=garden[tail];
            tail++;
        }
        if(sum == inrow && head-tail-inrow < best){
            best = head-tail-inrow;
            if(!found_one) found_one = true;
        }
    }
    if(found_one)
        cout <<best <<"\n";
    else
     cout <<"NIE\n";
    
    

}