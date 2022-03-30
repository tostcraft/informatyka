#include<iostream>
#include<ctime>
#include<random>
using std::cout;
using std::cin;

/*I won't comment this this is self explanatory*/
void print_arr(int ** arr, int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout <<arr[i][j] <<" ";
        }
        cout <<"\n";
    }
}

int ** &random_fill(int ** &arr, int n){
    std::srand(time(NULL));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
        {
            //set every cell in a given array to either 0 or 1
            arr[i][j] = rand()%2;
        }
    }

    // 3/4 of the time...
    if(rand()%4>0){
        //... select a random node to set as an idol...
        int idol = rand()%n;
        cout <<"IDOL SELECTED ON " <<idol <<"\n";
        for(int i = 0; i<n; i++){
            //... set the corresponding row to 0 only (no connections out)...
            arr[idol][i] = 0;
            //... and set the corresponding column to 1 only (connections in from every node).
            arr[i][idol] = 1;
        }
    }
    return arr;
}

int main(){
    int n;
    cin >>n;
    
    //prepearing an array for graph representation 
    //where cell [i, j] represents a connection from [i] to [j]
    int ** connections = new int*[n];
    for(int i = 0; i<n; i++){
        connections[i] = new int[n]{0};
    }

    //randomly connect the graph
    random_fill(connections, n);
    print_arr(connections, n, n);


    int can = 0;//set the candidate to 0th node
    for(int newcan = 1; newcan<n; newcan++){//for each possible candidate...
        if(can!=newcan && connections[can][newcan] == 1){//... if the current candidate has a connection to the new candidate...
            can = newcan;//... set the candidate to new candidate.
        }
    }
    /*
    The loop above works because since an idol is a node to which every other node has a direct connection
    and the idol itself has none, eventually we will find a connection represented as [candidate][idol] and by
    following this connection we end up at the idol from which we have no options of going out.
    */

    bool is_idol = true;
    //do a linear search of the candidate's column and row...
    for(int i = 0; i<n; i++)
    {
        if(i == can) continue; //... continue if we'd check the cell[candidate][candidate]...
        if(connections[i][can]!= 1 || connections[can][i] != 0){
            /*
            ...if even a single node has no direct connection to the candidate
            or if the candidate has a direct connection to any other node then it's not the idol.
            */
            is_idol = false;
            break;
        }
    }
    if(is_idol)
    {
        cout <<"IDOL FOUND ON "<<can <<"\n";
    }
    else
    {
        cout <<"IDOL DOES NOT EXIST!\n"; 
    }

    return 0;
}