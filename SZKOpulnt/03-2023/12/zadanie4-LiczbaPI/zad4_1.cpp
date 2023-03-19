#include<iostream>
#include<fstream>

using std::cout;
using std::cin;

int main(){
    int radius = 200;
    int mid_x = 200, mid_y=200;

    std::ifstream points("punkty.txt");

    int x, y;
    int cntr_in = 0, cntr_on = 0;
    for(int i = 0; i<10000; i++){
        points >>x >>y;
        long long distance_squared = (x-mid_x)*(x-mid_x)+(y-mid_y)*(y-mid_y);
        if(distance_squared == radius*radius){
            cout <<x <<" " <<y <<"\n";
        }
        else if(distance_squared<radius*radius){
            cntr_in++;
        }
    }
    cout <<cntr_in;
    

    points.close();
    cout <<"\n";
    return 0;
}