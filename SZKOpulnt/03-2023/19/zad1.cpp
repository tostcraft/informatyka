#include<fstream>
#include<iostream>


using std::ifstream;
using std::cout;

void print_arr(const int *arr, int n){
    for(int i = 0;i<n;i++){
        cout <<arr[i] <<" ";
    }

}

int main(){
    #if 0
    ifstream input1("przyklad1.txt");
    ifstream input2("przyklad2.txt");
    #else
    ifstream input1("dane1.txt");
    ifstream input2("dane2.txt");
    #endif

    int* line1 = new int[10];
    int* line2 = new int[10];
    int counter = 0;

    while(input1>>line1[0]){
        input2>>line2[0];
        for(int i = 1; i<10; i++){
            input1>>line1[i];
            input2>>line2[i];
        }
        if(line1[9] == line2[9]){
            print_arr(line1, 10);
            cout <<" <-> ";
            print_arr(line2, 10);
            cout <<"\n"; 
            counter++;
        }
    }
    cout <<counter <<"\n";


    delete line1;
    delete line2;
    input1.close();
    input2.close();
    return 0;
}