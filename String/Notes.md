/*********************************************************************************************

Question :


Notes :
    string s = "geeksforgeeks";
 
    int n = s.length();

    
    // assigning value to string s
    string s("geeksforgeeks");

In plain terms, short-circuiting means stopping evaluation once you know that the answer can no longer change. For example, if you are evaluating a chain of logical ANDs and you discover a FALSE in the middle of that chain, you know the result is going to be false, no matter what are the values of the rest of the expressions in the chain. Same goes for a chain of ORs: once you discover a TRUE, you know the answer right away, and so you can skip evaluating the rest of the expressions.
Topics:
pattern searching ~ diff algorithim
sliding window


Convert character array to string in C++
https://www.geeksforgeeks.org/convert-character-array-to-string-in-c/?ref=lbp


What’s difference between “array” and “&array” for “int array[5]” ?
https://www.geeksforgeeks.org/whats-difference-between-array-and-array-for-int-array5/
any array name itself is a pointer to the first element but & (i.e. address-of) for the array name is a pointer to the whole array itself.

int arr[] = { 1, 2, 3, 4, 5, 6 };
int size = *(&arr + 1) - arr;

**********************************************************************************************/