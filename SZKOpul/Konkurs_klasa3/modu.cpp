#include<iostream>
#include<array>

using std::cin; using std::cout;

int main(){
    std::array<bool, 37> accounted = {false};
    int a;
    int counter = 0;
    for(int i = 0; i<15; i++){
        cin >>a;
        a=a%37;
        if(!accounted[a]){
            counter++;
            accounted[a] = true;
        }
    }
    cout << counter <<"\n";

}