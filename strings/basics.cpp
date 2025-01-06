#include<iostream>
using namespace std;
int getLength(string str){
    int len=0;
    for(int i=0;str[i]!='\0';i++){
        len++;
    }
    return len;
}
void reverse(char name[],int n){
    int start=0,end=n-1;
    while(start<end){
        swap(name[start],name[end]);
        start++,end--;
    }
}
int main(){
    string str1="hiii ANU HERE";        // Declare and initialize the string
    string str2("how are uuu");         // Initialization by raw string
    cout<<str1<<endl<<str2<<endl;
    char name[20]="anu goyal";
    cout<<name<<endl;                   // -> anu goyal
    char name1[20];
    cout<<"enter ur name:";
    cin>>name1;                         // eg if I enter anu goyal O/p -> anu
    cout<<name1<<endl;                  // coz cin -> stops execution when we give it newline,space ,tab
    char name2[20];
    cout<<"enter ur name:";
    cin>>name2;
    name2[2]='\0';                         // eg. anushka -> o/p -> an
    cout<<name2<<endl;
    cout<<"length:"<<getLength(str1)<<endl;
    int n=getLength(name); 
    reverse(name,n);
    cout<<"reversed string:"<<name<<endl;
}