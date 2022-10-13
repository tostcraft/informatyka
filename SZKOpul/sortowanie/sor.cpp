#include<iostream>
#include<array>
using std::cout;
using std::cin;

void print_array(std::string *arr, int s, int n){
    for(int i = s; i<n; i++){
        cout <<arr[i] <<"\n";
    }
}

/*
returns true if s1 has less characters or is first in leksycal order
returns false if the opposite
*/
bool compare_strings(std::string s1, std::string s2){
    if(s1.size()<s2.size()) return true;
    else if(s1.size()>s2.size()) return false;

    for(int i = 0; i<s1.size(); i++){
        if(s1[i] < s2[i]) return true;
        else if(s1[i]>s2[i]) return false;
    }
    return true;
}

void merge(std::string arr[], int p, int q, int r){
    
    std::string *left = new std::string[q-p+1];
    std::string *right = new std::string[r-q];

    std::string *merged = new std::string[r-p+1];

    for(int i = 0; i<q-p+1; i++){
        left[i] = arr[p+i];
    }
    for(int i = 0; i<r-q; i++){
        right[i] = arr[q+i+1];
    }

    int marker1 = 0, marker2 = 0;

    while(marker1 < q-p+1 && marker2 < r-q){
        if(compare_strings(left[marker1], right[marker2])){
            merged[marker1+marker2] = left[marker1];
            marker1++;
        }
        else{
            merged[marker1+marker2] = right[marker2];
            marker2++;
        }
    }
    
    for(int i = marker1; i<q-p+1; i++){
        merged[marker2+i] = left[i];
    }
    for(int i = marker2; i<r-q; i++){
        merged[marker1+i] = right[i];
    }

    for(int i = 0; i<r-p+1; i++){
        arr[i+p] = merged[i];
    }

}

void mergesort(std::string * arr, int p, int r){
    if(p>=r) return;
    int q = (p+r)/2;
    mergesort(arr, p, q);
    mergesort(arr, q+1, r);
    merge(arr, p, q, r);
}

int main()
{
    
    int n;
    cin >>n;
    const std::size_t N = n;
    std::string jewels[150];
    for(int i = 0; i<n; i++){
        std::string s;
        cin >>s;
        jewels[i] = s;
    }
    mergesort(jewels, 0, n-1);
    print_array(jewels, 0, n);

    return 0;
}