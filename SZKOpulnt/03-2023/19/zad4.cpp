#include<fstream>
#include<iostream>


using std::ifstream;
using std::cout;

void print_arr(const int *arr, int n){
    for(int i = 0;i<n;i++){
        cout <<arr[i] <<" ";
    }

}

int * merge(const int * arr1, const int * arr2, int n){

    int * final = new int[2*n];

    int marker1 = 0;
    int marker2 = 0;

    while(marker1<n && marker2 <n){
        if(arr1[marker1]<=arr2[marker2]){
            final[marker1+marker2] = arr1[marker1];
            marker1++;
        }
        else{
            final[marker1+marker2] = arr2[marker2];
            marker2++;
        }
    }

    while(marker1<n){
        final[marker1+marker2] = arr1[marker1];
        marker1++;
    }

    while(marker2<n){
        final[marker1+marker2] = arr2[marker2];
        marker2++;
    }

    return final;

}

int main(){
    #if 0
    ifstream input1("przyklad1.txt");
    ifstream input2("przyklad2.txt");
    #else
    ifstream input1("dane1.txt");
    ifstream input2("dane2.txt");
    #endif

    std::ofstream output("wyniki4_4.txt");

    int* line1 = new int[10];
    int* line2 = new int[10];

    while(input1 >> line1[0]){
        input2>>line2[0];
        for(int i = 1; i<10; i++){
            input1>>line1[i];
            input2>>line2[i];
        }

        int *merged = merge(line1, line2, 10);
        for(int i = 0; i<20; i++){
            output <<merged[i] <<" ";
            cout <<merged[i] <<" ";
        }
        output<<"\n";
        cout <<"\n";

    }





    delete line1;
    delete line2;
    input1.close();
    input2.close();
    output.close();

    return 0;
}