
***************************
Unordered set
***************************

Unordered sets are containers that store unique elements in no particular order, and which allow for fast retrieval of individual elements based on their value.


In an unordered_set, the value of an element is at the same time its key, that identifies it uniquely. Keys are immutable, therefore, the elements in an unordered_set cannot be modified once in the container - they can be inserted and removed, though.

find : 
Return value
An iterator to the element, 

erase :
  myset.erase ( myset.begin() );                    // erasing by iterator
  myset.erase ( "France" );                         // erasing by key return 1 if element exist else 0
  myset.erase ( myset.find("Japan"), myset.end() ); // erasing by range

insert : 
The insert of unordered_set returns a pair with the second element representing whether the element is actually inserted.