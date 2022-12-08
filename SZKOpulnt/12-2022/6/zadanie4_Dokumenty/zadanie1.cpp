#include<iostream>
#include<fstream>
#include<vector>
using std::cout;
using std::cin;


int main()
{
    std::ifstream input("identyfikator.txt");
    std::ofstream output("wyniki4_1.txt");
    std::string line;
    std::vector<std::string> saved_lines;
    int maxsum = 0;
    while(std::getline(input, line)){
        int linesum = 0;
        for(int i = 3; i<9; i++){
            linesum+=line[i]-48;
        }
        if(linesum>maxsum){
            maxsum = linesum;
            saved_lines.clear();
            saved_lines.push_back(line);
        }
        else if(linesum == maxsum){
            saved_lines.push_back(line);
        }
    }
    for(std::string s: saved_lines){
        cout <<s <<"\n";
        output <<s <<"\n";
    }   
    input.close();
    output.close();
    return 0;
}