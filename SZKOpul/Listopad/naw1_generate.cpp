#include<iostream>
#include<fstream>
#include<random>
#include<stack>
using std::cout;
using std::cin;


int main()
{
    std::ofstream file("naw1_data.txt");
    char opening[4] = {'(', '[', '{', '<'};
    char closing[4] = {')', ']', '}', '>'};
    std::srand(time(NULL));
    for(int i =0; i<20; i++){
        int seed = rand();
        int n = seed%10+1;
        file <<n <<"\n";
        for(int j = 0; j<n; j++){
            int len = seed % 20+2;
            if(seed%10 >2){
                len=(seed%15+1)*2;
            }
            std::stack<char> last_type;
            char * expression = new char[len];
            for(int k = 0; k<len; k++){
                seed = rand();
                if((seed%100<45 && !last_type.empty()) || (last_type.empty() && seed%100<95)){
                    expression[k] = opening[seed%4];
                    last_type.push(expression[k]);
                }
                else{
                    if(seed%1000<850 && !last_type.empty()){
                        char a;
                        if(last_type.top()=='('){
                            a = ')';
                            last_type.pop();
                        }
                        else if(last_type.top()=='['){
                            a = ']';
                            last_type.pop();
                        }
                        else if(last_type.top()=='{'){
                            a = '}';
                            last_type.pop();
                        }
                        else if(last_type.top()=='<'){
                            a = '>';
                            last_type.pop();
                        }
                        expression[k] = a;
                    }
                    else{
                        expression[k] = closing[seed%4];
                    }
                }
            }
            file.write(expression, len);
            file <<"\n";
        }
    }
    file.close();
    return 0;
}