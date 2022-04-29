#include<iostream>
#include<algorithm>
using std::cin; using std::cout;

int main(){
    int sides[3] = {0, 0, 0};
    cin >>sides[0]; 
    cin >>sides[1]; 
    cin >>sides[2];
    std::sort(sides, sides+3);
    int relation = sides[2]*sides[2] - (sides[0]*sides[0]+sides[1]*sides[1]);
    if(relation<0){
        cout << "O\n";
    }
    else if(relation==0){
        cout <<"P\n";
    }
    else{
        cout <<"R\n";
    }
    return 0;
}