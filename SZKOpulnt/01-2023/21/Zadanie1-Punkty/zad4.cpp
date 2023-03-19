#include<fstream>
#include<iostream>

using std::cout;

int main(){

    std::ifstream file("punkty.txt");
    int square_side = 5000;
    int inside = 0, edging = 0, outside = 0;
    int x, y;
    while(file >>x){
        file >>y;
        if(x<square_side&& y<square_side) inside ++;
        else if(x == square_side || y == square_side) edging ++;
        else outside ++;
    }
    file.close();
    cout <<inside <<" " <<edging <<" " <<outside <<"\n";
    return 0;
}