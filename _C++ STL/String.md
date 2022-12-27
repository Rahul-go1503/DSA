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


# substring - 
https://www.geeksforgeeks.org/substring-in-cpp/
>1. substr -
It generates a new string with its value initialized to a copy of a sub-string of this object.
[pos, pos+len).

Syntax - string substr(int pos, int len);
TC - O(N);

***
to_string() - number to string

> string to number
- We are not allowed to perform type casting because int and string both are not in the same Object hierarchy.
https://www.geeksforgeeks.org/converting-strings-numbers-c-cpp/

#include <sstream>
int main()
{
	string s = "12345";

	// object from the class stringstream
	stringstream geek(s);

	// The object has the value 12345 and stream
	// it to the integer x
	int x = 0;
	geek >> x;

	// Now the variable x holds the value 12345
	cout << "Value of x : " << x;

	return 0;
}

1. int stoi(string s,int pos, int base);
2. int atoi(char* s);
3. float atof(char* s);

> StringStream
https://www.geeksforgeeks.org/stringstream-c-applications/
https://www.simplilearn.com/tutorials/cpp-tutorial/string-stream-in-cpp

# Note
<!-- a = a + "xy" is O(N) while a += "xy" is O(1) (amortized).
a = a + "xy" creates a copy of a, appends "xy" and then assigns it back to a.
a += "xy" just appends "xy" to a. -->
