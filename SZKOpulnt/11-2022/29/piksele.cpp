#include<iostream>
#include<fstream>
using std::cout;
using std::cin;

std::pair<int, int> zadanie1(int ** arr){
    std::pair<int, int> maxmin(0, 256);
    for(int i = 0; i<200; i++){
        for(int j = 0; j<320; j++){
            if(arr[i][j] > maxmin.first){
                maxmin.first = arr[i][j];
            }
            if(arr[i][j] < maxmin.second){
                maxmin.second = arr[i][j];
            }
        }
    }
    return maxmin;
}

int zadanie2(int **arr){
    int counter = 0;
    for(int i = 0; i<200; i++){
        for(int j = 0; j<160; j++){
            if(arr[i][j]!=arr[i][319-j]){
                counter++;
                break;
            }
        }
    }
    return counter;
}

int zadanie3(int**arr){
    int counter = 0;
    for(int  i =0; i<200; i++){
        for(int j = 0; j<320; j++){
            if(j!=0 && std::abs(arr[i][j]-arr[i][j-1])>128){
                counter++;
            }
            else if(j!=319 && std::abs(arr[i][j]-arr[i][j+1])>128){
                counter++;
            }
            else if(i!=0 && std::abs(arr[i][j]-arr[i-1][j])>128){
                counter++;
            }
            else if(i!=199 && std::abs(arr[i][j]-arr[i+1][j])>128){
                counter++;
            }

        }
    }
    return counter;
}

int zadanie4(int ** arr){
    int maxlen = 0;
    for(int i = 0; i<320; i++){
        int len = 1;
        int last = arr[0][i];
        for(int j = 1; j<200; j++){
            if(arr[j][i] == last){
                len++;
            }
            else{
                if(maxlen<len) maxlen = len;
                last = arr[j][i];
                len = 1;
            }
        }
        if(maxlen<len) maxlen = len;
    }
    return maxlen;
}

int main()
{
    std::ifstream data("dane.txt");
    int ** arr = new int*[200];
    for(int i = 0; i<200; i++){
        arr[i] = new int[320]{0};
    }

    for(int i = 0; i<200; i++){
        for(int j = 0; j<320; j++){
            data >> arr[i][j];
        }
    }
    data.close();


    std::pair<int, int> odp1 = zadanie1(arr);
    cout <<"MAX: " <<odp1.first <<" | MIN: " <<odp1.second <<"\n";

    int odp2 = zadanie2(arr);
    cout <<odp2 << "\n";

    int odp3 = zadanie3(arr);
    cout <<odp3 <<"\n";

    int odp4 = zadanie4(arr);
    cout <<odp4 <<"\n";

    delete arr;
    return 0;
}