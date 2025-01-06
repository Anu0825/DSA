#include<iostream>
#include<vector>
using namespace std;
bool issafe(int row,int col,vector<vector<int>> &board,int val){
    for(int i=0;i<board.size();i++){
        // row check
        if(board[row][i]==val){
            return false;
        }
        // col check
        if(board[i][col]==val){
            return false;
        }
        // 3*3 matrix check
        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board){
    int n=board[0].size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            // cell empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(issafe(row ,col,board,val)){
                        board[row][col]=val;
                        //recursive call
                        bool ageSolutionPossible=solve(board);
                        if(ageSolutionPossible)
                            return true;
                        else{
                            //backtrack
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &board){
     solve(board);
}
int main(){
    vector<vector<int>> board;
    for(int i=0;i<9;i++){
        vector<int> row;
        for(int j=0;j<9;j++){
            int value;
            cin>>value;
            row.push_back(value);
        }
        board.push_back(row);
    }
    solveSudoku(board);
    for(auto i:board){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
