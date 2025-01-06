#include<iostream>
#include<vector>
using namespace std;
int elemAtSpecificPos(int row,int col){
    // Ist method generate all the pattern and then give the elem at given location
    // 2nd method (directly) -> it is given by (n-1)C(r-1)
    // calculation nCr
      long long int ans=1;
      for(int i=0;i<col;i++){
          ans=ans*(row-i);
          ans=ans/(i+1);
      }
      return ans;
}
void TogenerateSpecificRow(int row){
    for(int c=1;c<=row;c++){
        cout<<elemAtSpecificPos(row-1,c-1)<<" ";
    }
}
/*vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
 b
        }
    }*/
void generate_pascal(int numRows){
    for(int i=1;i<=numRows;i++){
        TogenerateSpecificRow(i);
        cout<<endl;
    }
}
int main(){
    int rows;
    cout<<"enter rows:";
    cin>>rows;
    cout<<elemAtSpecificPos(6-1,3-1)<<endl;
    TogenerateSpecificRow(5);
    cout<<endl<<"pascal triangle is:"<<endl;
    generate_pascal(rows);
}