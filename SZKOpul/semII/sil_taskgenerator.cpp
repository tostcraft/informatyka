#include<iostream>
#include<fstream>
#include<random>
using std::cout;
using std::cin;
typedef long long huge;

const uint32_t BITS32 = ~0;

int main()
{
    std::ofstream file("tests.txt");
    std::srand(time(NULL));
    huge num1, num2;
    file <<"100000\n";
    for(int i = 0; i<100000; i++){
        num1 = rand()/INT16_MAX;
        num1 = num1*(rand()%64);
        num1 = num1%10000000000000;
        // cout <<num1 <<"\n";
        file <<num1;
        num2 = rand()/INT16_MAX;
        num2 = num2*(rand()%64)+num1;
        num2 = num2%(10000000000000-num1);
        // cout <<num1 <<"\n";
        file << " " <<num2 <<"\n";
    }
    file.close();
    return 0;
}