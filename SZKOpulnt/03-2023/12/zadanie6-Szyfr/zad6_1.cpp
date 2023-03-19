#include<fstream>
#include<iostream>

char encode(char c, int offset){
    return 'A'+(c+offset%26-'A')%26;
}

int main(){

    int o = 107;
    std::string s;
    std::ifstream data("dane_6_1.txt");
    std::ofstream output("wyniki_6_1.txt");

    while(data>>s){
        for(char c:s){
            output <<encode(c, o);
        }
        output <<"\n";
    }

    data.close();
    output.close();

    return 0;
}