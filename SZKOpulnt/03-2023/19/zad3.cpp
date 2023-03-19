#include<fstream>
#include<iostream>


using std::ifstream;
using std::cout;

void print_arr(const int *arr, int n){
    for(int i = 0;i<n;i++){
        cout <<arr[i] <<" ";
    }

}

bool same_nums(int * arr1, int * arr2, int n){

    bool * counted1 = new bool[101]{false};
    bool * counted2 = new bool[101]{false};

    for(int i = 0; i<n; i++){
        counted1[arr1[i]] = true;
        counted2[arr2[i]] = true;
    }

    for(int i = 0; i<101; i++){
        if(counted1[i]!=counted2[i]){
            return false;
        }
    }
    return true;

}

int main(){
    #if 0
    ifstream input1("przyklad1.txt");
    ifstream input2("przyklad2.txt");
    const int size = 5;
    #else
    ifstream input1("dane1.txt");
    ifstream input2("dane2.txt");
    const int size = 1000;
    #endif

    int* line1 = new int[10];
    int* line2 = new int[10];
    int counter=0;

    for(int k = 0; k<size; k++){
        for(int i = 0; i<10; i++){
            input1>>line1[i];
            input2>>line2[i];
        }

        if(same_nums(line1, line2, 10)){
            cout <<k+1 <<", ";
            // print_arr(line1, 10);
            // cout <<" | ";
            // print_arr(line2, 10);
            // cout <<"\n";
            counter++;
        }
    }

    cout <<"\n"<<counter <<"\n";


    delete line1;
    delete line2;
    input1.close();
    input2.close();

    return 0;
}