#include<fstream>
#include<iostream>

char decode(char c, int offset){
    return 'A'+(c-offset%26+'Z'+1)%26;
}

int main(){

    int o;
    std::string s;
    std::ifstream data("dane_6_2.txt");
    std::ofstream output("wyniki_6_2.txt");


    while(data >>s >>o){
        for(char c:s){
            output <<decode(c, o);
        }
        output <<"\n";
    }

    data.close();
    output.close();

    return 0;
}