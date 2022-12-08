#include <iostream>
#include <fstream>
using std::cin;
using std::cout;

int char_convert(char c)
{
    if(std::isdigit(c))
        return (int)c-48;
    return (int)c - 65 + 10;
}

int main()
{
#if 0
    std::ifstream input("identyfikator_przyklad.txt");
#else
    std::ifstream input("identyfikator.txt");
#endif
    std::ofstream output("wyniki4_3.txt");
    int weight[9] = {7, 3, 1, 0, 7, 3, 1, 7, 3};
    cout << (int)'1' << "\n";
    std::string line;
    while (std::getline(input, line))
    {
        int sum = 0;
        int contr = char_convert(line[3]);
        for (int i = 0; i < 9; i++)
        {
            sum += weight[i] * char_convert(line[i]);
        }
        if(sum%10!=contr){
            cout << line <<"\n";
            output <<line <<"\n";
        }
    }

    input.close();
    output.close();
    return 0;
}