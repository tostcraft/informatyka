#include <iostream>
using std::cin;
using std::cout;

std::string convert(std::string data)
{
    std::string to_return = "";

    for (char c : data)
    {
        if (c == 'z'){
            to_return+='0';
        }
        if (c == 'j')
            to_return.insert(to_return.begin(), '1');
    }
    return to_return;
    

}

int get_num(std::string s){
    int outcome = 0;
    int power = 1;
    while(s.size()>0){
        char digit = s.back();
        if(digit == '1'){
            outcome+=power;
        }
        s.pop_back();
        power*=2;
    }
    return outcome;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::string input;
    std::getline(cin, input);
    std::string binary = convert(input);
    cout <<binary << " " <<get_num(binary) <<"\n";
    return 0;
}