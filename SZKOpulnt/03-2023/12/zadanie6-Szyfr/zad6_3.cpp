#include<fstream>
#include<iostream>

int main(){

    std::string s1, s2;
    std::ifstream data("dane_6_2.txt");
    std::ofstream output("wyniki_6_2.txt");


    while(data >>s1 >>s2){
        for(int i = 0; i<s1.size(); i++){
            
        }
        output <<"\n";
    }

    data.close();
    output.close();

    return 0;
}