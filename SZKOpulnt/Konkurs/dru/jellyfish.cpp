#include <iostream>
#include <vector>

using std::cin;
using std::cout;

struct Player{
    int pos;
    bool * visited = new bool[100000]{false};
}foo;

int main(){
    int n;
    cin >>n;
    int* map = new int[n]{0};
    for(int i = 0; i<n; i++){
        cin >>map[i];
    }
    
    Player p1, p2, p3;
    cout <<"\n";
    return 0;
}