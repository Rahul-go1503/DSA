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
}


>find :
    auto itr = find(v.begin(),v.end(),value_to_find);


>iterators to index :
    itr - v.begin();
- only in vectors

>front :
>back :
-If the vector container is empty, it causes undefined behavior. 

>Difference between front(), back() and begin, end() function

begin() and end() function return an iterator(like a pointer) initialized to the first or the last element of the container that can be used to iterate through the collection, while front() and back() function just return a reference to the first or the last element of the container.

return type - itr
upper_bound :
Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
// less than hai less than hai...... equal hai equal hai.... are ye to badi hai return krdo


lower_bound :
Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.

// less than hai less than hai.... are ye to eqaul hai return krdo... agar equal nhi hai to bdi value return krdo... bdi nhi to end itr return krdo

eq.
10 10 10 20 20 20 30 30
lower_bound at position 3
upper_bound at position 6


>erase : 
    while(A[0]==0) A.erase(A.begin());
    1. vectorname.erase(position)
    2. vectorname.erase(startingposition, endingposition)
    Parameters :
    Position of the element to be removed in the form of iterator.
    or the range specified using start and end iterator.
    Result :
    Elements are removed from the specified
    position of the container.

insert :
A.insert(A.begin(),1);

> Allocate memory for the returned vector is potentially better than keeping push_back.
 initially a vector has a size of 1 everytime we pushback and the vector runs out of space it creates a new vector of double the previous size and copies all the previous elements to it and pushes the new element to the new vector this is very expensive so its better to preallocate memory to vector whenever possible

reverse vector of vector :
 




