#include <iostream>
using std::cin;
using std::cout;

// long literal_approach(long arr[], long n){
//     long counter = 0;
//     for (long i = 1; i < n; i++){
//         long index = i;
//         for (int j = i - 1; j >= 0; j--){
//             if (arr[index] > arr[j])
//                 break;
//             long hold = arr[j];
//             arr[j] = arr[index];
//             arr[index] = hold;
//             index = j;
//             counter++;
//         }
//     }
//     return counter;
// }

void merge(long arr[], long s, long mid, long e, long long &counter){//array, start, mid, end
    

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
            counter+=mid-s+1-marker1;
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
    return;

}

void mergesort(long arr[], long s, long e, long long &counter){
    if(s<e){
        long mid = (s+e)/2;
        mergesort(arr, s, mid, counter);
        mergesort(arr, mid+1, e, counter);
        merge(arr, s, mid, e, counter);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n;
    cin >> n;
    long long count = 0;
    long *cards = new long[n];
    for (int i = 0; i < n; i++){
        cin >> cards[i];
    }
    mergesort(cards, 0, n-1, count);
    cout <<count <<"\n";
    return 0;
}