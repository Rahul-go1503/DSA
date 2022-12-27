# we can not assgin array to another array like vector
- arr1 = arr2 <!--invalid  --> array not modify

# char Array -

    a.b : a is class b is method ;
    a-> : a is pointer to a class (*a).b
# we cannot initialize variable size array
    int arr[k] = {}; // wrong , here we get k from function call
    int arr[k];
    memset(arr,0,sizeof(arr)); // Right way


vector<int> a[]={{2,3,4},{2}};
>here a is a pointer pointing to a[0] means vector<int> or a container or class(Vector)
<!-- cout<<a.size(); -->
cout<<a->size();

int a[] = {1,2};
>a is a pointer pointing to a int type
>type of a is int*
<!-- cout<<a.size(); -->
cout<<sizeof(a)/sizeof(int);

*****
> arr is the pointer to the first memory block
    arr[] is might be equil to *arr
    arr[i] == *(arr+i);
- We pass pointer to the array(memory block) in a function.
>Sort the array a[] in increasing order.
    sort(a, a + n);
>Sort the array b[] in decreasing order.
    sort(b, b + n, greater<int>());
>Size of an Array:
    int n = sizeof(arr)/sizeof(int);

    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
> copy
    copy (arr1, arr1+size, arr2);
-  Shallow copying is when two different array names (old and new) refer to the same content in memory. Deep copying is when the two different array names refer to two independent, but same content, in memory

*****
# Dutch National Flag
> 2-way Partitioning 
1. a[1..Lo-1] zeroes
2. a[Lo..Hi] unknown
3. a[Hi+1..N] ones

> 3-way Partitioning 
1. a[1..Lo-1] zeroes (red)
2. a[Lo..Mid-] ones (white)
3. a[Mid..Hi] unknown
4. a[Hi+1..N] twos (blue)

*****
# Dynamic memory allocation
> new makes call to the constructor
> Pointer initialization to null
    int* p = NULL;
> Array
    int *arr = new int[size];
> Dynamic array of pointer having size 10 using new is created as,
    int **arr = new int *[10];

> What happens when delete is used for a NULL pointer?
    int *ptr = NULL;
    delete ptr;
- Deleting a null pointer has no effect, so it is not necessary to check for a null pointer before calling delete.

> Is it fine to call delete twice for a pointer?
- NO
- It is undefined behavior to call delete twice on a pointer. Anything can happen, the program may crash or produce nothing.

## memory release
> pointer_variable
    delete p;
> block of memory
    delete[] p;