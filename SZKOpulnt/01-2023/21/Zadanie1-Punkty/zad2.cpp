#include<fstream>
#include<iostream>

using std::cout;

bool numberlike(int a, int b){
    bool * a_digits = new bool[9]{false};
    while(a>0){
        a_digits[a%10-1] = true;
        a = a/10;
    }
    while(b>0){
        if(!a_digits[b%10-1]){
            return false;
        }
        b = b/10;
    }
    return true;
}

int main(){

    std::ifstream file("punkty.txt");

    int counter = 0;
    int x, y;
    for(int i = 0; i<1000; i++){
        file >>x;
        file >>y;
        cout <<'.'; //it just works!
        if(numberlike(x, y)) {counter++;cout <<x <<" " <<y <<"\n";}
    }
    file.close();
    cout <<"\n"<<counter << "\n";
    return 0;
}