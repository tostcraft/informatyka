#include<iostream>
#include<fstream>
#include<random>
using std::cout;
using std::cin;


int main()
{
    std::srand(time(NULL));
    std::ofstream file("testy.txt");
    if(!file.is_open()){
        cout <<"Could not open file\n";
        return 1;
    }
    for(int i = 0; i<1000; i++){
        for(int j =0; j<20; j++){
            int val = rand();
            if(val%2==0){
                file <<'(';
            }
            else{
                file <<')';
            }
        }
        file <<"\n";
    }
    file.close();
    return 0;
}