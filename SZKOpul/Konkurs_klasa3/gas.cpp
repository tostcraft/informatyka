#include<iostream>
#include<array>
#include<vector>

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
    int min = 1000000;
    int marker = 0;
    for(int i = 0; i<gardensize-inrow; i++){
        if(garden[i] == 1){
            int sum = 1;
            marker = i+1;
            while(sum<inrow && marker<gardensize){
                sum+=garden[marker];
                marker++;
            }
            int to_eat = marker-i-inrow;
            if(to_eat<min){
                found_one = true;
                min = to_eat;
            }
        }
    }
    if(found_one)
        cout <<min <<"\n";
    else
        cout <<"NIE\n";
    
    

}