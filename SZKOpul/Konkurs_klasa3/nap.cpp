#include<iostream>
#include<array>
using std::cin; using std::cout;

//work in progress

int main(){
    
    int d, n;
    cin >>d;
    int a;
    for(int i = 0; i<d; i++){
        std::array<int, 500> nums = {0};
        cin >> n;
        for(int j = 1; j<=n; j++){
            if(j%2==0)
            {
                cin >>a;
                cout <<a << " ";
            }
            else{
                cin >>nums[j/2];
            }
        }
        int count = 0;
        while(nums[count]>0){
            cout <<nums[count] <<" ";
            count ++;   
        }
        cout <<"\n";
    }
    
}