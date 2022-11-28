# Questions:
> print all substring
> print all subsequence
# Functions:
> strstr 
- strstr finds a sub-string within a string
- Prototype: char * strstr(const char *s1, const char *s2); 
> strcpy
> strcat



# erase - 
>1. Deletes all characters [first,end)
    str.erase();
>2.  Deletes all characters except first three [idx,end)
	str.erase(3); 3 se aage ke del
>3. Deletes 3 characters from index number 3-- [idx,count}
    str.erase(3, 3); idx 3 bhi del hoga

>4. Deletes character at position 4
    str.erase(str.begin() + 4); // return next itr last del kra to end

>5.  Deletes all characters [first , Last)
	str.erase(str.begin() + 0, str.end() - 1);
