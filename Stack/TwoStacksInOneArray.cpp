// implement two stacks in 1 array
#include<iostream>
using namespace std;
class TwoStack{
    int *arr;
    int size;
    int top1;
    int top2;
    TwoStack(int s){
        this -> size=s;
        arr= new int[s];
        top1=-1;
        top2=s;
    }
    //push in stack1
    void push1(int element){
        //at least 1 empty space is present
        if((top2-top1)>1){   
            top1++;
            arr[top1]=element;
        }
        else{
            cout<<"stack overflow";
        }
    }
    //push in stack2
    void push2(int element){
        if((top2-top1)>1){   
            top2--;
            arr[top2]=element;
        }
        else{
            cout<<"stack overflow";
        }
    }
    //pop from stack 1 and return popped element
    int pop1(){
        if(top1>=0){
            int ans= arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }
    //pop from stack 2 and return popped element
    int pop2(){
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }

};
int main(){
}
