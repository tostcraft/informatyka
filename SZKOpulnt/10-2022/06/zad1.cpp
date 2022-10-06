#include<iostream>
#include<stack>


void to_binary(std::stack<int> numbers){
    while(numbers.size()>0){
        int num = numbers.top();
        while(num>0){
            std::cout << num%2;
            num/=2;
        }
        numbers.pop();
        std::cout <<"\n";
    }
}

int main(){
    int n;
    std::cin >>n;
    std::stack<int> my_stack;
    int data;
    for(int i = 0; i<n; i++){
        std::cin >>data;
        my_stack.push(data);
    }

    std::cout <<"\n";
    to_binary(my_stack);
    return 0;
}