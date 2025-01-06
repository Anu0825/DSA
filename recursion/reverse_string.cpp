#include<iostream>
using namespace std;
void rev_str(string& str,int i,int j){
    if (i>j)
        return ;
    swap(str[i],str[j]);
    return rev_str(str,i+1,j-1);
}
int main(){
cout<<"enter string:"<<endl;
string str;
cin>>str;
rev_str(str,0,str.length()-1);
cout<<str<<endl;
}
//or using only 1 pointer
/*#include<iostream>
using namespace std;
void rev_str(string& str,int i,int n){
    if (i>(n-i-1))
        return ;
    swap(str[i],str[n-i-1]);
    return rev_str(str,i+1,n-i);
}
int main(){
cout<<"enter string:"<<endl;
string str;
cin>>str;
rev_str(str,0,str.length());
cout<<str<<endl;
}*/
