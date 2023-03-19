#include<iostream>
#include<fstream>
#include<iomanip>

using std::cout;
using std::cin;

int main(){
    int radius = 200;
    int mid_x = 200, mid_y=200;


    std::ifstream points("punkty.txt");
    std::ofstream temp("temp.txt");

    double pi;

    int x, y;
    int cntr_in = 0;
    for(int i = 1; i<=1700; i++){
        points >>x >>y;
        long long distance_squared = (x-mid_x)*(x-mid_x)+(y-mid_y)*(y-mid_y);
        if(distance_squared<=radius*radius){
            cntr_in++;
        }
        pi = 4*(double)cntr_in/(double)i;
        temp <<i <<" " <<std::setprecision(5) <<pi <<"\n";
    }

    temp.close();
    points.close();
    cout <<"\n";
    return 0;
}