#include<iostream>
#include<stack>



int main(){
    std::string data;
    std::getline(std::cin, data);
    std::stack<char> my_stack;
    for(char &c: data){
        if(c == '(') my_stack.push(c);
        else if(c == ')' && my_stack.size()>0) my_stack.pop();
    }

    if(my_stack.size()==0) std::cout <<"TAK";
    else std::cout <<"NIE";


    std::cout <<"\n";
    return 0;
}