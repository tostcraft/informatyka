#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int a, b;
  std::cin >> a >> b;
  if(a>b){
      std::cout<<"FALSTART";
  }
  else{
      std::cout<<b-a;
  }
}