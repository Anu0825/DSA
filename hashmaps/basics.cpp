// in case of map comp -> O(log n)
// in unordered map comp -> O(1) based on hashtable
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string,int>m;
    //insertion
    //1 method
    pair<string,int> p=make_pair("babbar",3);
    m.insert(p);
    //2 method
    pair<string,int> pair2("love",2);
    m.insert(pair2);
    // 3 method
    m["mera"]=1;
    m["mera"]=2; // -> this will update the "mera"-> 2 at place of 1
    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    //cout<<m.at("unknown")<<endl; // -> error if key is not present
    cout<<m["unknown"]<<endl;    // -> will intialize to 0 if key is not present (no error)
    cout<<"size: "<<m.size()<<endl;
    // to check presence
    cout<<m.count("love")<<endl;        // count-> if key present will give 1 otherwise 0
    //erase
    m.erase("love");
    cout<<"size: "<<m.size()<<endl;
    // for traversing
    // 1 method
    for(auto i:m){                    // in unordered map order will not sme
        cout<<i.first<<" "<<i.second<<endl;
    }
    // 2 method using iterator
    unordered_map<string,int> :: iterator it=m.begin();
    while(it != m.end()){
        cout<< it->first <<" "<< it->second<<endl;
        it++;
    }
}