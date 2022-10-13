#include <iostream>
#include <fstream>
#include <stack>
using std::cin;
using std::cout;


void print_board(int **board, int n){
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            cout << board[row][col] <<" ";
        }
        cout <<"\n";
    }
}

void brute_force(int n, int **board)
{

    bool **checked = new bool *[n];
    for(int i = 0; i<n; i++){
        checked[i] = new bool[n]{false};
    }
    int *coords = new int[2]{0, 0}; // x y
    int moves[8][2] = {
        {0, 3}, {2, 2}, {3, 0}, {2, -2}, {0, -3}, {-2, -2}, {-3, 0}, {-2, 2}}; // +x +y
    std::stack<int*> to_check;
    to_check.push(coords);
    int depth = 1;
    while(!to_check.empty()){
        coords = to_check.top();
        to_check.pop();
        for(int i = 0; i<8; i++){
            int *move = moves[i];
            int *next_move = new int[2]{coords[0]+move[0], coords[1]+move[1]};
            if(next_move[0]>=0 && next_move[0]<n){
                if(next_move[1]>=0 && next_move[1]<n){
                    if(!checked[next_move[0]][next_move[1]]){
                        to_check.push(next_move);
                    }

                }
                    
            }
            cout <<"\n";
        }
        
        checked[coords[0]][coords[1]] = !checked[coords[0]][coords[1]];
        board[coords[0]][coords[1]] = depth++;
        cout <<"ENDING LOOP\n";
    }
    print_board(board, n);
}

int main()
{

    int n;
    cin >> n;
    int **board = new int *[n];
    for(int i = 0; i<n; i++){
        board[i] = new int[n]{0};
    }
    board[0][0] = 1;
    brute_force(n, board);

    return 0;
}