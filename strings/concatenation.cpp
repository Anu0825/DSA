#include<iostream>
#include<string.h>            // -> included for strcat() operation
using namespace std;
int main(){
    string str1="hii guyzz";        // Declare and initialize the string
    string str2="anu here";         // Initialization by raw string
    // method 1 -> using append
    str1.append(str2);
    cout<<str1<<endl;
    // method 2 -> using + operator
    str1="this is init";
    str2=" added now";
    str1=str1+str2;
    cout<<str1<<endl;
    // method 3 -> using strcat()
    char init[] = "this is init";
    char add[] = " added now";
    strcat(init, add);
    cout<<init<<endl;
    //method 4 -> using for loop
    string init1("this is init");
    string add1(" added now");
    string output;
    for (int i = 0; init1[i] != '\0'; i++) 
    {
        output += init1[i];
    }
    for (int i = 0; add1[i] != '\0'; i++) 
    {
        output += add1[i];
    }
    cout << output << endl;
}