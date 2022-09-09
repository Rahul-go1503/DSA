*****
# Ordered Set
Insert all array elements into the set:
>  set<int> s(arr, arr + N);
>	advance(itr, K - 1); // itr points to kth element in set
	cout << *itr << "\n";
  //error
	cout << *(itr+ K-1) << "\n";
>implemented using Self-Balancing Binary Search Tree(AVL Tree)

> distance:
  distance(s.begin(),s.begin()+x);
  Range is [first,last);
  return no of elem
  TC - O(1) for random-acesss pointers O(N) for other
*****
# Unordered set

> Unordered sets are containers that store unique elements in no particular order, and which allow for fast retrieval  of individual elements based on their value.

> In an unordered_set, the value of an element is at the same time its key, that identifies it uniquely. Keys are immutable, therefore, the elements in an unordered_set cannot be modified once in the container - they can be inserted and removed, though.

> find : 
  Return value
  An iterator to the element, 

> erase :
  myset.erase ( myset.begin() );                    // erasing by iterator
  myset.erase ( "France" );                         // erasing by key return 1 if element exist else 0
  myset.erase ( myset.find("Japan"), myset.end() ); // erasing by range

> insert : 
  The insert of unordered_set returns a pair with the second element representing whether the element is actually inserted.

# multi_set:
- https://www.geeksforgeeks.org/multiset-in-cpp-stl/
> similar to the set, with the exception that multiple elements can have the same values
> store in sorted manner so log(N) operations