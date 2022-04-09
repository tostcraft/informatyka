#include<iostream>

using std::cin;
using std::cout;

int main(){
    long long* connections = new long long[6];
    for(int i = 0; i<6; i++)
    {
        cin >>connections[i];
    }

    long long around, hourglass1, hourglass2;
    around = connections[0]+connections[1]+connections[4]+connections[5];
    hourglass1 = connections[0]+connections[2]+connections[3]+connections[5];
    hourglass2 = connections[1]+connections[2]+connections[3]+connections[4];

    if(around <= hourglass1 && around<=hourglass2)
    {
        cout <<around;
    }
    else if(hourglass1<=around && hourglass1<=hourglass2)
    {
        cout <<hourglass1;
    }
    else
    {
        cout <<hourglass2;
    }

    cout <<"\n";

    return 0;
}
