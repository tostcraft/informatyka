#include<iostream>
#include<fstream>

using std::cin;
using std::cout;

bool is_valid(std::string line){
    int last = line.size()-1;
    if(line[0]==line[2]){
        return true;
    }
    for(int i = 3; i<6; i++){
        if(line[i]!=line[last-i+2]){
            return false;
        }
    }
    return true;
}

int main(){

    std::ifstream input("identyfikator.txt");
    std::ofstream output("wyniki4_2.txt");

    std::string line;
    while(std::getline(input, line))
    {
        if(is_valid(line)){
            cout <<line <<"\n";
            output <<line <<"\n";
        }
    }

    input.close();
    output.close();
    return 0;
}