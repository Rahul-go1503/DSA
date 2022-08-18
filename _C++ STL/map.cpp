#include <bits/stdc++.h>
using namespace std;

void read1(map<int,int> &m){
    for(int i=0;i<10;i++){
        m[i]=i+1;
    }
}
void read2(map<int,int> &m){
    cout<<" NOT good \n";
    auto itr = m.begin();
    for(int i=0;i<10;i++){
        // itr++->first=i;  ERROR
        itr++->second=i+1;
    }
}
void read3(map<int,int> &m){
    cout<<" NOT good \n";
    auto itr = m.begin();
}

void print1(map<int,int> &m){
    cout<<"BY For loop : \n";
    for(int i=0;i<10;i++){
        cout<<m[i]<<" ";
    }
    cout<<endl;
}
void print2(map<int,int> &m){
    cout<<"BY itrator : \n";
    auto itr=m.begin();
    while(itr!=m.end()){
    cout<<itr++->second<<" ";
    }
    cout<<endl;
}
void print3(map<int,int> &m){
    cout<<"BY auto : \n";
    for(auto val:m) cout<<val.second<<" ";
    cout<<endl;
}

int main(){
    map<int,int> m;
    read1(m);
    print1(m);
    print2(m);
    print3(m);


}