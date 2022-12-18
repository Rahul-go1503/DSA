void read1(map<int,int> &m){
    for(int i=0;i<10;i++){
        m[i]=i+1;
    }
}
void read2(map<int,int> &m){
    cout<<" NOT good \n";
    auto itr = m.begin();
    for(int i=0;i<10;i++){
        // itr++->first=i;  ERROR - Can't update key?
        itr++->second=i+1; // Can update value
    }
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

# unordered_map

>count : count the no of keys present in map
Parameters: This function accepts a single parameter key which is needed to be checked in the given unordered_map container.
Return Value: This function returns 1(coz map store distinct values) if there exists a value in the map with the given key, otherwise it returns 0.

>find:
Parameters: It takes the key as a parameter.

Return values: If the given key exists in unordered_map it returns an iterator to that element otherwise it returns the end of the map iterator.


> m.count and m[] are duplicated operations. replacing it with an iterator can save half of the map operations.
 Both m.count(n) and m[n] search the key n in unordered_map<int, int> m. In ans.push_back(m.count(m) ? m[n] : -1), we search the key n twice, once to see if it's in m and again to get it's value. Since the time complexity of search operations on an unordered_map is O(1), it doesn't have a big impact on performance, but nevertheless, we want to cut corners where we can. Also, on containers like map or set, search operations are not O(1). By using unordered_map<int, int>::find and iterators, we can reference it right away once we find it instead of doing another search for the key.