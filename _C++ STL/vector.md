void read(vector<int> & v,int n){
    cout<<"Enter in read func \n";
    int i=0;
    while (n--)
    {
        // v[i++]=i+1;
        v.push_back(i+++1);
    }
    
}

void print(vector<int> &v){
    cout<<"Enter in print func \n";
    for(auto val: v) cout<<val<<" ";
    cout<<endl;
}
int main(){
    vector<int> v;
    int n=10;
    read(v,n);
    print(v);


find :
    auto itr = find(v.begin(),v.end(),value_to_find);


iterators to index :
    itr - v.begin();
}


upper_bound :
Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
// less than hai less than hai...... equal hai equal hai.... are ye to badi hai return krdo


lower_bound :
Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.

// less than hai less than hai.... are ye to eqaul hai return krdo

eq.
10 10 10 20 20 20 30 30
lower_bound at position 3
upper_bound at position 6


erase : 
while(A[0]==0) A.erase(A.begin());

insert :
A.insert(A.begin(),1);




