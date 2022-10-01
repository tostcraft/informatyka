#include<iostream>
#include<algorithm>
using std::cout;
using std::cin;



// long brute_force(long arr[], long r){
//     long min = __LONG_MAX__;
//     for(long i = 0; i<r; i++){
//         long sum = 0;
//         for(int j = 0; j<r; j++){
//             sum+=std::abs(arr[i]-arr[j]);
//         }
//         if(sum<min) min = sum;
//     }
//     return min;
// }

void merge(long arr[], long s, long mid, long e){//array, start, mid, end
    
    // cout <<"HERE: " <<s <<" " <<mid  <<" " <<e <<"\n";
    long *leftside = new long[mid-s+1]; //left-side help array
    long *rightside = new long[e-mid]; //right-side help array
    long *mergedarr = new long[e-s+1]; //merging array


    //copy the data to side arrays
    for(int i = s; i<=mid; i++){
        
        leftside[i-s] = arr[i]; 
        // cout <<i-s <<":" <<leftside[i-s] <<" ";
    }
    // cout <<"\n";
    for(int i = mid+1; i<=e; i++){
        rightside[i-mid-1] = arr[i]; 
        // cout <<i-mid-1 <<":"<<rightside[i-mid-1] <<" ";
    }
    // cout <<"\nDATA REWRITTEN\n";
    //sorting until we run into the end of one o the arrays
    long marker1 = 0, marker2 = 0;
    while(marker1<=mid-s && marker2<e-mid)
    {
        // cout <<"SORTING: " <<leftside[marker1] <<" " <<rightside[marker2] <<"\n";
        if(leftside[marker1] <= rightside[marker2]){
            mergedarr[marker1+marker2] = leftside[marker1];
            marker1++;
        }
        else{
            mergedarr[marker1+marker2] = rightside[marker2];
            marker2++;
        }
    }

    //finishing the merge by filling the array with what's left after previous step
    for(int i = marker1; i<=mid-s; i++){
        // cout <<i <<" " <<i+marker2 <<" " <<leftside[i] <<"\n";
        mergedarr[i+marker2] = leftside[i];
    }
    for(int i = marker2; i<e-mid; i++){
        // cout <<i <<" " <<i+marker1 <<" " <<rightside[i] <<"\n";
        mergedarr[i+marker1] = rightside[i];
    }

    //rewriting the merged data into main array
    for(int i = 0; i<=e-s; i++){
        // cout <<mergedarr[i] <<" ";
        arr[i+s] = mergedarr[i];
    }
    // cout <<"\n";
    delete leftside;
    delete rightside;
    delete mergedarr;

}

void mergesort(long arr[], long s, long e){
    if(s<e){
        long mid = (s+e)/2;
        mergesort(arr, s, mid);
        mergesort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
}

long long sorted_approach(long arr[], long r){
    mergesort(arr, 0, r-1);
    long middle = arr[r/2];
    long long sum = 0;
    for(long i = 0; i<r; i++){
        sum+=std::abs(middle-arr[i]);
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long r; //array length
    cin >>r;
    long *house_arr = new long[r]; //main data array
    for(long i = 0; i<r; i++){
        cin >> house_arr[i]; 
    }
    // long bruteforceresult = brute_force(house_arr, r);
    long long sortedresult = sorted_approach(house_arr, r);


    cout <<sortedresult <<"\n";

    return 0;
}